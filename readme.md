# C++ Boilerplate
[![Build Status](https://travis-ci.org/KrishnaBhatu/Week4808x.svg?branch=master)](https://travis-ci.org/KrishnaBhatu/Week4808x)
[![Coverage Status](https://coveralls.io/repos/github/KrishnaBhatu/Week4808x/badge.svg?branch=master)](https://coveralls.io/github/KrishnaBhatu/Week4808x?branch=master)
---
## Author
```
[Driver]-Krishna Suresh Bhatu(KrishnaBhatu)
[Navigator]-Bhargav Dandamudi(bhargav-umd) 
```
## Overview
```
Desiging a PID controller to achieve a setpoint velocity.

Following if the block diagram for the working of PID algorithm.
<img src = "https://upload.wikimedia.org/wikipedia/commons/thumb/4/43/PID_en.svg/971px-PID_en.svg.png" style = "width:100px ; height:100px " />
```
##Working
```
The controller calculates error which we get from the setpoint value and the actual value
Now, 3 parameters are calculated for getting the actual velocity such that the error is minimized and the actual value reaches the setpoint value.
1) The Proportional parameter: This parameter gets affected directly by the error. So, for larger errors we get a large change in the actual value.
2) The integral parameter: This parameter is defined as the integral of parameter over time. So, when the error is less, the proportional term tends to reduce and the effects of the integral term comes to be visible.
3) The derivative term: This parameter is defines as the derivative of the error with respect to time. It provides a dampering effect, so for rapid changes in the error, this provides a greater controlling effect and dampers the error.
The formula for PID algorithm is:
<img src = "https://wikimedia.org/api/rest_v1/media/math/render/svg/69072d4013ea8f14ab59a8283ef216fb958870b2)" style = "width:100px ; height:100px " />
```
## Standard install via command-line
```
git clone --recursive https://github.com/dpiet/cpp-boilerplate
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```


## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml


