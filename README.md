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

## usage.

look at the tests under ```src/main.cpp```
on how to use the code.
it is fairly straightforward.
operations that can be done include:
append, prepend, pop, push, insert, and getting the length() of the list.
something really simple might look like:
```c++
#include <linkedlist.h>

LinkedList<int> alist;

// [42]
alist.append(42);

// [41, 42]
alist.prepend(41);

// [40, 41, 42]
// returns: true if inserting inside list else false
alist.insert(0, 40);

// [40, 41, 42, 43]
alist.push(0, 43);

// [40, 41, 42]
// returns: 43
alist.pop();

// returns 3
alist.length();
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


