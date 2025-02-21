# libpath <!-- omit in toc -->

Path parsing library (for C and C++)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
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

* [STLSoft 1.11](http://github.com/synesissoftware/STLSoft-1.11/);
* [xTests](http://github.com/synesissoftware/xTests/);


### Related projects

* [**libpath.Go**](https://github.com/synesissoftware/libpath.Go);
* [**libpath.Ruby**](https://github.com/synesissoftware/libpath.Ruby);
* [**libpath.Rust**](https://github.com/synesissoftware/libpath.Rust);
* [**recls**](https://github.com/synesissoftware/recls);


### License

**libpath** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

