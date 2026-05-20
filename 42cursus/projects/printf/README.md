*This project has been created as part of the 42 curriculum by mnoda-ta*

## Description
This project consists of an implementation of the `printf` function from `libc`.

The function can handle the following conversions:
- **%c** Prints a single character.
- **%s** Prints a string.
- **%p** Prints a void pointer in hexadecimal format.
- **%d** Prints a decimal number.
- **%i** Prints an integer in base 10.
- **%u** Prints an unsigned decimal number.
- **%x** Prints a number in lowercase hexadecimal format.
- **%X** Prints a number in uppercase hexadecimal format.
- **%%** Prints a percent sign.

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
- [Abusing the C preprocessor for better variadic function arguments.](https://snai.pe/posts/varargs)
- [Unraveling the Magic of Variadic Functions in C](https://medium.com/@emretemir/unraveling-the-magic-of-variadic-functions-in-c-fee1ca657221)
- [char type in va_arg](https://stackoverflow.com/questions/28054194/char-type-in-va-arg)
- [Statically Typed vs Dynamically Typed Languages](https://www.baeldung.com/cs/statically-vs-dynamically-typed-languages)
- [Size of Pointers in C](https://www.geeksforgeeks.org/c/size-of-pointers-in-c/)

## Implementation Details

For this project, I chose to have each auxiliar function (e.g ft_putchar, ft_putstr) return an `int` representing the number of bytes printed. This decision was based on:
- **Error Handling**: By returning the result of write, the project ensures that any system-level failure is not ignored. An error at any point in the printing process will bubble up to the main function, ensuring a consistent return value of -1 upon failure.

- **Code Clarity**: It simplifies the debugging process by pinpointing exactly which function call encountered an issue.

- **Encapsulation**: Ensuring that each function manages its own state without relying on side effects or shared mutable pointers.

#### Algorithm and Data Structure
**The Parsing Algorithm**: The function iterates through the format string character by character. When a regular character is encountered, it is printed directly. When a % sign is found, the algorithm steps forward to read the next character (the specifier) and uses a conditional branch to redirect the execution to the appropriate helper function.

### AI usage in this project:

- Translation from Portuguese to English.
- Grammar checking and proofreading for the README and codebase files.
- Technical explanations regarding variadic variables and memory behaviors.
