# MPI ABI Stubs

A reference implementation of the MPI Standard ABI with C header and stub
library for testing and development.

## Overview

This project provides a complete stub implementation of the MPI Application
Binary Interface (ABI) as specified in [MPI 5.0 Chapter 20][mpi50-report].

[mpi50-report]: https://www.mpi-forum.org/docs/mpi-5.0/mpi50-report.pdf

This project provides:

- **`mpi.h`**: C header file exposing MPI ABI specification
- **`mpilib.c`**: C source code for building the stub shared library
- **Compiler wrappers**: `mpicc` and `mpicxx` for building MPI applications

This implementation is primarily intended for:

- Building MPI applications with a lightweight compile-time dependency
- Testing MPI ABI compatibility and conformance
- Reference for MPI ABI implementers

> [!CAUTION]
> The MPI ABI stubs are **not** meant for running MPI applications. By design,
> most MPI functions in the stub library are non-functional and call `abort()`
> upon invocation. At runtime, use a proper MPI ABI implementation.

## Features

- Complete MPI ABI specification
- Cross-platform support (Linux, macOS, Windows)
- Multiple build systems (GNU Make, CMake, Meson)
- Weak symbol bindings for MPI/PMPI function pairs

## Building

### Prerequisites

- C compiler (GCC, Clang, or MSVC)
- One of: GNU Make, CMake (≥3.10), or Meson (≥1.1.0)

### Build with Make

```bash
make build
make install PREFIX=/path/to/install
```

### Build with CMake

```bash
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/path/to/install ..
cmake --build .
cmake --install .
```

See the convenience script `build-cmake.sh`.

### Build with Meson

```bash
meson setup build --prefix=/path/to/install
meson compile -C build
meson install -C build
```

See the convenience script `build-meson.sh`.

## Usage

After installation, use the provided compiler wrappers:

```bash
# Update PATH
export PATH=/path/to/install/bin:$PATH

# Compile C programs
mpicc -o myapp myapp.c

# Compile C++ programs
mpicxx -o myapp myapp.cpp
```

The wrappers automatically add the correct include and library paths and link
against the `mpi_abi` shared library.

### Example Program

```c
// myapp.c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int version, subversion;
    int abi_major, abi_minor;

    MPI_Get_version(&version, &subversion);
    MPI_Abi_get_version(&abi_major, &abi_minor);

    printf("MPI std version: %d.%d\n", version, subversion);
    printf("MPI ABI version: %d.%d\n", abi_major, abi_minor);

    return 0;
}
```

## Project Structure

```
mpi-abi-stubs/
├── VERSION         # Project version file
├── mpi.h           # MPI ABI header file
├── mpilib.c        # Library stubs implementation
├── mpilib.def      # Visual Studio module-definition
├── mpicc.in        # Template for mpicc/mpicxx wrappers
├── Makefile        # GNU Make build system
├── CMakeLists.txt  # CMake build system
├── meson.build     # Meson build system
├── pyproject.toml  # Python packaging configuration
├── update.py       # Script to update header and stubs
└── test/           # Tests for build system support
```

## Implementation Notes

### Stub Functions

Most MPI functions in the stub library are non-functional and call `abort()`
when invoked. This is by design, the library is primarily meant for:

- **Compile-time** compatibility testing
- **Link-time** verification
- **Build system** integration

The MPI ABI stubs are **not** meant for running MPI applications. To execute
MPI programs, dynamically link at runtime against a real MPI implementation
(MPICH, Open MPI, Intel MPI, etc.).

```bash
MPI_LIBDIR=$I_MPI_ROOT/lib # for Intel MPI
MPI_LIBDIR=/path/to/mpi/lib # for MPICH or Open MPI
export LD_LIBRARY_PATH=$MPI_LIBDIR:$LD_LIBRARY_PATH # for Linux
export DYLD_LIBRARY_PATH=$MPI_LIBDIR:$DYLD_LIBRARY_PATH # for macOS
```

### ABI Compatibility

The header and library follow the MPI Standard ABI specification, ensuring
binary compatibility across different MPI implementations that support the MPI
ABI. This means applications compiled/linked against this header/library can be
dynamically linked with any ABI-compliant MPI library at runtime.

### MPI Profiling Interface

By relying on weak symbol support, the MPI profiling interface allows the
interception of MPI calls. Each `MPI_Xxx` function is a weak symbol and calls
the corresponding `PMPI_Xxx` implementation.

## Development

### Updating Declarations

The project includes an `update.py` script to automatically generate
and update in-place:

- Project version in `VERSION`
- PMPI function declarations from MPI declarations in `mpi.h`
- Visual Studio module-definition in `mpilib.def`

```bash
python update.py
```

This ensures consistency between MPI and PMPI interfaces and reduces
the maintenance burden when updating to new MPI ABI versions.

### Running Tests

```bash
# Build in-place
make

# Run basic checks
bash -x check.sh

# Run GNU Make tests
make -C test

# Run CMake and Meson tests
cd test
./test-cmake.sh
./test-meson.sh
```

## Contributing

Contributions are welcome! Please ensure:

- Code follows the existing style
- All three build systems (GNU Make, CMake, Meson) are updated
- Run `update.py` after adding/modifying declarations
- Test on multiple platforms when possible

## License

See [LICENSE.md](LICENSE.md) file for details.

## References

- [MPI Forum Website](https://www.mpi-forum.org/)
- [MPI 5.0 Document](https://www.mpi-forum.org/docs/mpi-5.0/mpi50-report.pdf)
- [MPI ABI Working Group](https://github.com/mpiwg-abi/abi-issues)

## Citation

Jeff Hammond, Lisandro Dalcin, Erik Schnetter, Marc PéRache, Jean-Baptiste
Besnard, Jed Brown, Gonzalo Brito Gadeschi, Simon Byrne, Joseph Schuchart,
and Hui Zhou. 2023.  MPI Application Binary Interface Standardization.
In Proceedings of the 30th European MPI Users' Group Meeting (EuroMPI '23).
Association for Computing Machinery, New York, NY, USA, Article 1, 1-12.
https://doi.org/10.1145/3615318.3615319
https://arxiv.org/abs/2308.11214

```bibtex
@InProceedings{10.1145/3615318.3615319,
  author =     {Hammond, Jeff and
                Dalcin, Lisandro and
                Schnetter, Erik and
                P\'{e}Rache, Marc and
                Besnard, Jean-Baptiste and
                Brown, Jed and
                Gadeschi, Gonzalo Brito and
                Byrne, Simon and
                Schuchart, Joseph and
                Zhou, Hui},
  title =      {{MPI} {Application} {Binary} {Interface} Standardization},
  year =       2023,
  isbn =       9798400709135,
  publisher =  {Association for Computing Machinery},
  address =    {New York, NY, USA},
  url =        {https://doi.org/10.1145/3615318.3615319},
  doi =        {10.1145/3615318.3615319},
  articleno =  1,
  numpages =   12,
  keywords =   {MPI},
  location =   {Bristol, United Kingdom},
  series =     {EuroMPI '23}
}
```

## Acknowledgments

This project is part of the MPI Forum's effort to standardize the MPI
Application Binary Interface for improved application portability and
interoperability across MPI implementations.

Jeff Hammond ([@jeffhammond][gh-jeffhammond]) proposed and advocated for the
MPI ABI specification within the MPI Forum and wrote most of the MPI ABI
chapter in the MPI 5.0 document. Jeff also contributed the initial source code
for this MPI ABI stubs reference implementation.

Lisandro Dalcin ([@dalcinl][gh-dalcinl]) assisted Jeff with the formalities of
the MPI ABI proposal and made significant contributions to this MPI ABI stubs
reference implementation. Lisandro also contributed with thorough testing to
the MPI ABI development within the MPICH and Open MPI projects.

Hui Zhou ([@hzhou][gh-hzhou]) and Ken Raffenetti ([@raffenet][gh-raffenet])
implemented the MPI ABI specification within the [MPICH][gh-mpich] project.
Hui did most of that work while the MPI ABI specification was being shaped,
providing a most needed proof-of-concept for the proposal.

Howard Pritchard ([@hppritcha][gh-hppritcha]) and Jeff Squyres
([@jsquyres][gh-jsquyres]) implemented the MPI ABI specification within the
[Open MPI][gh-openmpi] project.

[gh-jeffhammond]: https://github.com/jeffhammond
[gh-dalcinl]:     https://github.com/dalcinl
[gh-hzhou]:       https://github.com/hzhou
[gh-raffenet]:    https://github.com/raffenet
[gh-hppritcha]:   https://github.com/hppritcha
[gh-jsquyres]:    https://github.com/jsquyres
[gh-mpich]:       https://github.com/pmodels/mpich
[gh-openmpi]:     https://github.com/open-mpi/ompi
