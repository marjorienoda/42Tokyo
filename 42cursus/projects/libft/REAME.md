# Project libft

This project has been created as part of the 42 curriculum by mnoda-ta.

## Description
This project consists of a custom C library (*libft.a*) that reimplements a set of standard C functions and adds useful functions for future assignments.

The objective of this project is to understand how standard
functions work, manage memory effectively, and manipulate data structures. The library is divided into three main sections:
- Part 1: reimplementation of standard libc functions(e.g., `ft_strlen`, `ft_strdup`).
- Part 2: functions for string and memory manipulation(e.g., `ft_itoa`, `ft_strmapi`).
- Part 3: functions for linked list manipulation (e.g., `ft_lstnew`).

## Instructions

#### Compilation

The project includes a `Makefile` with the followig rules:

| Rule          | Description                                             |
| -----------   | -----------                                             |
| `make`        | Compiles the functions and creates `libft.a`            |
| `make clean`  | Removes all the object files (.o)                       |
| `make fclean` | Removes all the object files and the compiled `libtf.a` |
| `make re`     | Perfoms a full recompilation (`fclean` + `make`).       |

#### How to use this library?

In your code include the header.
```
#include "libft.h"
```
And compile your project linking the library:
```
cc main.c libft.a -o my_program
```
## Resources

- [Memory Management in Operating System](https://www.geeksforgeeks.org/operating-systems/memory-management-in-operating-system/)
- [Makefile in C++ and its applications](https://www.geeksforgeeks.org/cpp/makefile-in-c-and-its-applications/)
- [Makefile Tutorial](https://makefiletutorial.com/#include-makefiles)
- [Unix Makefile](https://www.tutorialspoint.com/makefile/index.htm)
- [Makefile Automatic Variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)
- [CS50 Linked List](https://cs50.harvard.edu/x/weeks/5/)
- [Linked List in C](https://www.geeksforgeeks.org/c/linked-list-in-c/)
