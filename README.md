# libpath <!-- omit in toc -->

Path parsing library (for C and C++)


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/libpath.svg)](https://github.com/synesissoftware/libpath/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/libpath)](https://github.com/synesissoftware/libpath/commits/master)
[![CI](https://github.com/synesissoftware/libpath/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/libpath/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Developer Experience](#developer-experience)
- [Installation](#installation)
- [Components](#components)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
    - [Proper Dependencies](#proper-dependencies)
    - [Development Dependencies](#development-dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**libpath** is a small, standalone library, implemented in C with a C and a C++ API, that provides file-system path parsing and comparison, for platform-dependent - **Unix** and **Windows** - and platform-independent path manipulation. It is intended to be useful for application-level programming as well as a basis for other libraries.


## Developer Experience

**Need**: a C compiler and **CMake** 3.20+. Tests and examples also need [STLSoft](https://github.com/synesissoftware/STLSoft) **1.11.5** or later and [xTests](https://github.com/synesissoftware/xTests) **0.29** or later. The library itself needs only the C standard library (and the C++ standard library for the C++ API).

**Build**:

```bash
./prepare_cmake.sh
./build_cmake.sh
```

**Try**:

```bash
./run_all_unit_tests.sh
./run_all_examples.sh
```

**Simplest use** (C):

```C
#include <libpath/parse.h>

libpath_PathDescriptor_t desc;

libpath_Parse_ParsePathFromCStyleString("/tmp/a", 0, &desc, 0, NULL, NULL);
int const absolute = libpath_ParseResult_IsPathAbsolute(&desc);
```

**Simplest use** (C++):

```C++
#include <libpath/parse.hpp>

libpath::parsing::PathDescriptor_t desc;

libpath::parsing::parse_path_from_cstyle_string("/tmp/a", 0, &desc, 0, nullptr);
int const absolute = libpath_ParseResult_IsPathAbsolute(&desc);
```

**Read next**: [INSTALL.md](./INSTALL.md) for installation, the **examples** directory for usage, and [FAQ.md](./FAQ.md) for common questions.


## Installation

Detailed instructions - via **CMake** - are provided in the accompanying [INSTALL.md](./INSTALL.md) file.



## Components

* **Comparing API** (C and C++);
* **Equating API** (C and C++);
* **Parsing API** (C and C++);


## Examples

Examples are provided in the ```examples``` directory.


## Project Information


### Where to get help

[GitHub Page](https://github.com/synesissoftware/libpath "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/libpath.

If you'd like to help out with the project, please raise an issue via [GitHub Page](https://github.com/synesissoftware/libpath/issues "GitHub Page") - you'll be very welcome!


### Dependencies

#### Proper Dependencies

**libpath** has no proper (i.e. runtime / build) dependencies outside the facilities of the C standard library and, for its C++ API, the C++ standard library.


#### Development Dependencies

In order to run the test programs, **libpath** has the following development dependencies:

* [STLSoft](https://github.com/synesissoftware/STLSoft) **1.11.5** or later;
* [xTests](https://github.com/synesissoftware/xTests) **0.29** or later;


### Related projects

* [**libpath.Go**](https://github.com/synesissoftware/libpath.Go);
* [**libpath.Ruby**](https://github.com/synesissoftware/libpath.Ruby);
* [**libpath.Rust**](https://github.com/synesissoftware/libpath.Rust);
* [**recls**](https://github.com/synesissoftware/recls);


### License

**libpath** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

