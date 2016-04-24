---
layout: page
title: Building Empathy
---

# Building Empathy for Linux

So now you want to build Empathy for Linux? Here's how to meet the dependencies. But first, did you meet all the dependencies of Empathy? Otherwise, go over to [meet common dependencies.](../)

There are going to be so many flavors of Empathy: DEmpathy(Desktop + Empathy, made for linux but, works for any desktop), AEmpathy(Android + Empathy, not yet released), iEmpathy (iOS + Empathy, not yet released),
So choose the flavor you want to. And let's build Empathy in the flavor you like!

## Meeting Dependencies
Empathy has been kept away from unnecessary dependencies as much as possible, however, some dependencies must be met.
 
### Common Dependencies
**A C++ Compiler**: To compile the C++ project.

**make**: To make the project

**cmake**: To intelligent `make` the project

**pkg-config**: Finding packages in an OS can be very hard. That's where `pkg-config` plays by locating these packages[Used by `CMake`].

**GLEW**:
To make Empathy platform-independent, some uniform libraries are required. Empathy at the very core is made in close relation with GLEW.

**muparser**:
To parse mathematical expressions during runtime.

### DEmpathy

**GLFW3**
To show window, we need something. Let it be GLFW. 
 
**irrKlang**
To make music in DEmpathy aka DoonLight (MoonLight + Desktop!) 

## Installing Dependencies

### Linux
DEmpathy successfully builds up in Ubuntu 15.04 64-bit using the following procedure. I hope you approach a similar procedure for your Linux distro :)

Make:

    sudo apt-get install build-essential

CMake:

    sudo apt-get install software-properties-common
    sudo add-apt-repository ppa:george-edison55/cmake-3.x
    sudo apt-get update
    sudo apt-get install cmake

`pkg-config`:

    sudo apt-get install pkg-config

`GLEW` and `GLFW`:

    sudo apt-get install libglew-dev libglfw-dev libglfw3-dev

`irrKlang` is already placed in the DEmpathy/libs folder. Hurray! You have installed the dependencies!

### Windows
Okay Windows folks, I haven't tested this but the procedure goes something like this:

-Install the GCC compiler. Instructions can be found here: [http://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/](http://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/)

-Install [Make](http://gnuwin32.sourceforge.net/packages/make.htm] and (CMake)[https://cmake.org/download/)

-Install [pkg-config](http://stackoverflow.com/questions/1710922/how-to-install-pkg-config-in-windows)

-GLEW: Download GLEW from [here](https://sourceforge.net/projects/glew/files/glew/1.13.0/glew-1.13.0-win32.zip/download) and follow the instructions [here](http://glew.sourceforge.net/install.html)

-GLFW: Download from [here](http://www.glfw.org/download.html)

----------------
So let's hope that your installation is successful. If not, and you won't give up without compiling it from scratch, drop by a short mail on the address on the footer!

----------------------------------