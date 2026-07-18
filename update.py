#!/usr/bin/env python3
"""MPI ABI stubs updater."""

import os
import re

os.chdir(os.path.dirname(os.path.abspath(__file__)))

# Update mpi.h
# ------------

# read original mpi.h
with open("mpi.h") as file:
    contents = [line.rstrip() for line in file]

# parse contents and generate/replace declarations
pattern = r"^(\w+\s+)(MPI_\w+)"
replace = r"\1P\2"
functions = []
for prefix in ("MPI", "MPI_T"):
    # collect MPI/MPI_T function declarations
    try:
        marker = f"/* {prefix} functions */"
        s = contents.index(marker) + 1
        e = contents.index("", s)
    except ValueError:
        message = f"Cannot find '{marker}' in mpi.h"
        raise RuntimeError(message) from None
    funcs = contents[s:e]
    functions.extend(funcs)
    # generate and replace PMPI/PMPI_T function declarations
    try:
        marker = f"/* P{prefix} functions */"
        s = contents.index(marker) + 1
        e = contents.index("", s)
    except ValueError:
        message = f"Cannot find '{marker}' in mpi.h"
        raise RuntimeError(message) from None
    lines = [re.sub(pattern, replace, line) for line in funcs]
    contents[s:e] = lines

# write updated mpi.h
with open("mpi.h", "w") as file:
    for line in contents:
        file.write(f"{line}\n")


# Update mpilib.c
# ---------------

# read original mpilib.c
with open("mpilib.c") as file:
    contents = [line.rstrip() for line in file]

# remove generated content
try:
    marker = "/* MPI ABI implementation */"
    index = contents.index(marker) + 1
except ValueError:
    message = f"Cannot find '{marker}' in mpilib.c"
    raise RuntimeError(message) from None
del contents[index:]
contents.append("")

# collect implemented MPI functions
implemented = set()
implemented_re = re.compile(r"^\s*static\s+\w+\s+stubs_(MPI_\w+)\s*\(.*\)")
for line in contents:
    m = implemented_re.match(line)
    if m:
        implemented.add(m.group(1))

function_re = re.compile(r"^(\w+)\s+(P?MPI_\w+)\((.*)\);")
numtypes_re = re.compile(r"int|double|MPI_(?:Aint|Offset|Count)")
filterchars = str.maketrans(dict.fromkeys("*[]()"))

contents.extend([
    "#ifdef _MSC_VER",
    "#pragma warning ( disable : 4068 )",
    "#endif",
])

funcnames = []
for function in functions:
    # parse function signature
    m = function_re.match(function)
    if m is None:
        message = f"Cannot parse function signature: {function!r}"
        raise RuntimeError(message)
    rtype, name, argsdecl = m.groups()

    # save MPI function name
    funcnames.append(name)

    # parse argument names
    argnames = [
        arg.replace("[3]", "").translate(filterchars).split()[-1]
        for arg in argsdecl.split(",")
    ]
    if argnames[-1] == "...":
        argnames.pop()
    if "void" in argnames:
        argnames.remove("void")
    callargs = ", ".join(argnames)

    # emit blank line
    contents.append("")

    # emit MPI function
    contents.append(f"#pragma weak {name}")
    body = f"return P{name}({callargs});"
    func = f"{rtype} {name}({argsdecl}) {{ {body} }}"
    contents.append(func)

    # emit PMPI function
    if name in implemented:
        body = f"return stubs_{name}({callargs});"
    else:
        retexpr = "0"
        if not numtypes_re.match(rtype):
            retexpr = f"({rtype})NULL"
        body = f"abort(); return {retexpr};"
    func = f"{rtype} P{name}({argsdecl}) {{ {body} }}"
    contents.append(func)

# write updated mpilib.c
with open("mpilib.c", "w") as file:
    for line in contents:
        file.write(f"{line}\n")


# Update mpilib.def
# -----------------

# generate contents
contents = [
    "LIBRARY mpi_abi",
    "EXPORTS",
    *(f"    {fn}" for fn in funcnames),
    *(f"    P{fn}" for fn in funcnames),
]

# write updated mpilib.def
with open("mpilib.def", "w") as file:
    for line in contents:
        file.write(f"{line}\n")
