# MOS-6502-Simulator
A MOS 6502 simulator written in C++.

# Prerequisites

- vcpkg for getting Google Test library
- [Visual Studio 2019 Community](https://visualstudio.microsoft.com/zh-hant/vs/community/)
- [CC65](https://www.cc65.org/) for compiling C code to run on Simulator

# How to Use

## Compile Simulator

```shell
msbuild  "MOS 6502 Emulator.sln" -target:MOS_6502_Executable:Rebuild -p:Configuration=Debug,Platform=x86
```
> Note: It only allows to use "Debug | x86" mode to compile.

## Create a Hello World C Program

The memory address 0xFFFF is mapping to the console, so writing into the address means to print the word to console.

File: helloworld.c

```C
int main()
{
    char *console = (char *)0xFFFF;
    *console = 'H';
    *console = 'E';
    *console = 'L';
    *console = 'L';
    *console = 'O';
    *console = 'W';
    *console = 'O';
    *console = 'R';
    *console = 'L';
    *console = 'D';
    *console = '\n';

    return 0;
}
```

## Compile Program to Binary

```shell
cc65 helloworld.c --target sim6502
ca65 helloworld.s
ld65 -o helloworld -t sim6502 helloworld.o sim6502.lib
```

> Note: Please don't use cl65 to compile the c code. I don't know why, but it's not working.

## Run Binary on Simulator

Please put the simulator `MOS_6502_Executable.exe` and the binary `helloworld` in the same folder, and then type

```shell
MOS_6502_Executable.exe helloworld
```

you will see the output likes blew

```shell
the number of the arguments: 2
HELLOWORLD
Emulator is terminated. return code = 0
```