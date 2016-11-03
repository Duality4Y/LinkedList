# LinkedList

This is a implementation of a LinkedList in C++.
Currently only a singly linked list.
Goal was to learn what templates are how to use them.
And how memory management could be done in C++, through the use of shared_ptr.

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

### Installing

To use the code make sure your compiler finds ```cpp include/linkedlist.h```
And then simply include the code:
```
#include <linkedlist.h>
```

## Running the tests

For running the tests compile with
```
$ scons
```
And execute ```build/linkedlist```
no feedback meens all tests pass.

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


