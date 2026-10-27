# libpath - Changes <!-- omit in toc -->


## 0.3.0-beta3 - 27th October 2026

* Defined `HAS_xTests` and `HAS_XTESTS` when **xTests** is detected;


## 0.3.0-beta2 - 20th October 2026

* Aligned the **run_all_examples.sh**, **run_all_scratch_tests.sh** / **.cmd**, and **run_all_unit_tests.sh** helper scripts with **misc-dev-scripts** gold tip **0754c23**, excluding **CMakeFiles** and `*.d` / `*.o` / `*.obj` from discovery and adding scratch `--skip-interactive`;
* Raised `LIBPATH_VER_RELSTATUS` to `0x82` for **0.3.0-beta2**;


## 0.3.0-beta1 - 14th October 2026

* Applied **misc-dev-scripts** editor/Git/`.sis` drop-in templates (**.editorconfig**, **.gitattributes**, **.gitignore**, **.vimrc**, **.vscode/settings.json**);
* Added **.sis/project_name.txt** and **.sis/script_info_lines.txt**; listed **example.cpp.parse** in **.sis/ci_examples_allowed_to_fail.txt**;
* Aligned CMake helper scripts with **misc-dev-scripts** gold (SisClr), retaining **prepare_cmake.sh** `--stlsoft-root-dir` and `--simulate-windows-on-unix`;
* Added native Windows **run_all_*.cmd** runners and the full **run_all_*** suite (unit, component, automated, examples, scratch, performance);
* Added modular GitHub Actions CI (**ci.yml** / **ci-cell.yml**) with **install-sis-deps**, install-smoke, Windows `.cmd` dogfood, and execute-bit restore after artifact download;
* Added CMake scratch version reporter **test.scratch.versions** under **test/scratch/versions/**;
* Computed `LIBPATH_VER` from `LIBPATH_VER_MAJOR` / `_MINOR` / `_PATCH` / `_RELSTATUS` in **version.h**;
* Renamed the prerelease discriminator to `LIBPATH_VER_RELSTATUS` (`0x81` for **0.3.0-beta1**), retaining `LIBPATH_VER_ALPHABETA` as a documentation-hidden alias;
* Dropped a dead PRIVATE **STLSoft** link from the exported **core** target; absorbed `MSVC_USE_MT` in the top-level **CMakeLists.txt**;
* Registered unit tests via `add_test`; fixed **test.unit.parse.C** Windows path-offset and UNC compile issues;
* Shortened example directory/source to **examples/cpp/parse/** / **main.cpp** (target **example.cpp.parse**; formerly **example.cpp.parse.1**);
* Shortened unit-test directories to subject names under **test/unit/** (**compare**, **compare.C**, **equal**, **equal.C**, **parse**, **parse.C**, **shim-strings**, **type-strings**, **version**), with **entry.c** / **entry.cpp** sources and matching **test.unit.*** targets;
* Shortened scratch **test.scratch.compare.models** to **test/scratch/compare-models/** (**main.cpp**; target **test.scratch.compare-models**);
* Switched unit-test assertion statements to the **xTests** Terse API short forms (via **xtests/terse-api.h**);
* Created **CHANGES.md** from **HISTORY.md** and removed the subsumed **HISTORY.md**; upgraded **NEWS.md** to a three-column chronology with **Details**;
* Project boilerplate updates (**AUTHORS.md**, **FAQ.md**, **REQUISITES.md**, **TODO.md**, **LICENSE**, **README.md** CI badge and dependency links);


## 0.3.0-alpha1 - 15th March 2025

* Changed API;


## 0.2.0-alpha5 - 23rd February 2025

* Boilerplate tidying;


## 0.2.0-alpha4 - 23rd October 2024

* Minor updates;


## 0.2.0-alpha3 - 19th October 2024

* C++ overloads in the API;
* **CMake** build scripts enhancements;
* **CMake** improvements;
* MinGW compatibility;


## 0.2.0-alpha2 - 27th July 2024

* **CMake** compatibility;
* Windows compatibility;
* Visual C++ 17 compatibility;


## 0.1.5.21 - 11th February 2024

* Many changes;


## 0.1.4 - 20th November 2016

* Initial public release;


## 0.1.0 - 9th November 2012

* First (internal) implementation;


<!-- ########################### end of file ########################### -->
