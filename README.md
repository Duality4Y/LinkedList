# LinkedList

This is a implementation of a LinkedList in C++.
It is implemented as a Doubly linked list.
Goal was to learn what templates are how to use them, and how the work.
And I learned that C++ has this awesome feature, an object called shared_ptr,
that does refcounting for you, so you don't have to keep track of your pointers.
Shared_ptr calles the appropriate destructors, when pointer refcount reaches zero.

## Getting Started

Only environment tested is Linux.
to get the project and compile it,
clone the reposistory, and enter it.
and build with scons

```
$ git clone https://github.com/Duality4y/LinkedList
$ cd LinkedList
$ scons
```

### Prerequisites

scons for development and building.
(scons is buildscripts with python)
and a compiler (in my case gcc).

### Installing

To use the code make sure your compiler finds the file: linkedlist.h
(under include directory)
And then simply include the code:
```c++
#include <linkedlist.h>
```

## Running the tests

For running the tests compile with
```
$ scons
```
And execute ```build/linkedlist```
no feedback meens all tests pass.

## usage

look at the tests under ```src/main.cpp```
on how to use the code.
an example is provided in ```example/``` directory.
it is fairly straightforward.
operations that can be done include:
append, prepend, pop, push, insert, and getting the length() of the list.

the output of example1.cpp looks like:
```
alist.append(0)
[0]
alist.prepend(1)
[1, 0]
alist.insert(0, 42)
[1, 42, 0]
alist.insert(0, 43)
[1, 43, 42, 0]
alist.pop()
[1, 43, 42]
alist.push(80)
[1, 43, 42, 80]
```

## development

if there is a problem for example a test fails or something else happens.
you can build the code with debugging symbols on and no optimizations.
by doing:
```
$ scons devbuild
```
so that you can debug with for example: gdb.

## License

This project is licensed under GPL2 License - see the [LICENSE.md](LICENSE.md) file for details


