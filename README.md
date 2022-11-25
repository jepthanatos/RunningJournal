# Running Journal

What is a running journal?

A running journal, log or diary, is a record where you can keep track on your
runs, races, injuries, diet and pretty much anything else training-related.

What is this program meant to do?

This program will store a digital copy of a running journal.

In this early phase of the development the program will let you add, modify,
delete and save activities (training days and/or race days).

A training day will be compound by a warmup and one or more runs.

A race day will be compound by a warmup and one run.

The program will show information of this week activities and this month activities.

In more advanced phases the running journal will be complete with stadistics and
helpfull information about your runs.

## Installation

Download a zip and extract it:

    https://github.com/jepthanatos/RunningJournal/archive/refs/heads/main.zip

Or clone the repository:

    git clone https://github.com/jepthanatos/RunningJournal.git

## Compile in Windows

At least GCC 8 and CMake are needed.

Install MSYS2 from https://www.msys2.org/

https://github.com/msys2/msys2-installer/releases/download/2022-10-28/msys2-x86_64-20221028.exe

On the open console launch this command:

```
    pacman -S mingw-w64-ucrt-x86_64-gcc
```

Follow the update guide: https://www.msys2.org/docs/updating/

Configure using Cmake:

```
    "C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=G:\Programs\MSYS2\ucrt64\bin\x86_64-w64-mingw32-gcc.exe -DCMAKE_CXX_COMPILER:FILEPATH=G:\Programs\MSYS2\ucrt64\bin\x86_64-w64-mingw32-g++.exe -Sc:/<directory>/RunningJournal -Bc:/<directory>/RunningJournal/build -G "MinGW Makefiles"
```
**Pay attention to directories**

Compile:

```
    "C:\Program Files\CMake\bin\cmake.exe" --build c:<directory>/RunningJournal/build --config Debug --target all -j 6 --
```
**Pay attention to directories**
## Compile in Linux

At least GCC 8 and CMake are needed.

Install GCC 8:

```
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo-apt get update
    sudo apt-get install gcc-8 g++-8
```

Configure using Cmake:

```
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc-8 -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++-8 -S/<directory>/RunningJournal -B/<directory>/RunningJournal/build -G "Unix Makefiles"
```
**Pay attention to directories**

Compile:

```
    cmake --build ./build --config Debug --target all -j 10 --
```
**Pay attention to directories**
## Usage

    RunningJournal_run -i <input_file> [-o] [<output_file]

## Test

    RunningJournal_tst

## License

Attribution 4.0 International (CC BY 4.0)

https://creativecommons.org/licenses/by/4.0/
