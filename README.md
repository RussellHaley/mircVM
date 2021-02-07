# mircVM

The Mercy VM is a prototype "C Virtual Machine" based on the MIR VM and the C To MIR compiler, both of which are created by Vladimir Makarov. The purpose of this project it to gain experience working with MIR and deduce how difficult it would be to maintain a 32 bit variant, especially one capable of running on an arm-none-eabi (bare metal) platform (e.g Arm M4)

## Build on Ubuntu 20

Prerequisistes: GCC (e.g. build-essential), xmake, git 

NOTE: I have not linked the MIR repository so you must manually download and build MIR.

```
mkdir git; cd git
git clone https://github.com/RussellHaley/mircVM.git
cd mircVM
git submodule update --init
xmake b
```

Drop into the build directory and run set the run-file script executable:

```
chmod +x run-test.lua

```

Then run:

```
#Defaults to the existing sieve.c file
./run-test.lua <filename>
```
