## Resources
- [Abusing the C preprocessor for better variadic function arguments.](https://snai.pe/posts/varargs)
- [Unraveling the Magic of Variadic Functions in C](https://medium.com/@emretemir/unraveling-the-magic-of-variadic-functions-in-c-fee1ca657221)
- [char type in va_arg](https://stackoverflow.com/questions/28054194/char-type-in-va-arg)
- [Statically Typed vs Dynamically Typed Languages](https://www.baeldung.com/cs/statically-vs-dynamically-typed-languages)
- [Size of Pointers in C](https://www.geeksforgeeks.org/c/size-of-pointers-in-c/)

## Implementation Details

For this project, I chose to have each auxiliar function (e.g ft_putchar, ft_putstr) return an `int` representing the number of bytes printed. This decision was based on:
- **Robust Error Handling**: By returning the result of write, the project ensures that any system-level failure is not ignored. An error at any point in the printing process will bubble up to the main function, ensuring a consistent return value of -1 upon failure.

- **Code Clarity**: It simplifies the debugging process by pinpointing exactly which function call encountered an issue.

- **Encapsulation**: This approach follows functional programming principles, ensuring that each function manages its own state without relying on side effects or shared mutable pointers.

For this reason, I also chose the putnbr over itoa function to print the integer.

## AI

- translate from Portuguese to English
