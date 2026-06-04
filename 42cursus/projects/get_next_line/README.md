*This project was created as part of the 42 curriculum by mnoda-ta.*

## Description

## Instructions

#### Compilation

The project includes a `Makefile` with the following rules:

| Rule          | Description                                             |
| -----------   | -----------                                             |
| `make`        | Compiles the functions and creates `libftprintf.a`.     |
| `make clean`  | Removes all the object files (.o).                      |
| `make fclean` | Removes all object files and the compiled `libftprintf.a`.|
| `make re`     | Performs a full recompilation (`fclean` + `make`).      |

#### How to use this library?

In your code, include the header:
```c
#include "ft_printf.h"
```

And compile your project linking the library:

```
cc {my_program}.c libftprintf.a -o {my_program_out}
```

## Resources
- [Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Buffer in C Programmin](https://www.geeksforgeeks.org/c/buffer-in-c-programming/)
- [Input-output system calls](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)

## Implementation Details


#### AI usage in this project:


