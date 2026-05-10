*This project has been created as part of the 42 curriculum by mnoda-ta.*

## Description
This project consists of a custom C library (*libft.a*) that reimplements a set of standard C functions and adds useful functions for future assignments.

The objective of this project is to understand how standard functions work, manage memory effectively, and manipulate data structures. The library is divided into three main sections:
- **Part 1:** Reimplementation of standard libc functions (e.g., `ft_strlen`, `ft_strdup`).
- **Part 2:** Functions for string and memory manipulation (e.g., `ft_itoa`, `ft_strmapi`).
- **Part 3:** Functions for linked list manipulation (e.g., `ft_lstnew`).

## Instructions

#### Compilation

The project includes a `Makefile` with the following rules:

| Rule          | Description                                             |
| -----------   | -----------                                             |
| `make`        | Compiles the functions and creates `libft.a`            |
| `make clean`  | Removes all the object files (.o)                       |
| `make fclean` | Removes all the object files and the compiled `libft.a` |
| `make re`     | Performs a full recompilation (`fclean` + `make`).      |

#### How to use this library?

In your code include the header:
```c
#include "libft.h"
```

And compile your project linking the library:

```
cc main.c libft.a -o {my_program}
```
## Resources

- [Memory Management in Operating System](https://www.geeksforgeeks.org/operating-systems/memory-management-in-operating-system/)
- [Makefile in C++ and its applications](https://www.geeksforgeeks.org/cpp/makefile-in-c-and-its-applications/)
- [Makefile Tutorial](https://makefiletutorial.com/#include-makefiles)
- [Unix Makefile](https://www.tutorialspoint.com/makefile/index.htm)
- [Makefile Automatic Variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)
- [CS50 Linked List](https://cs50.harvard.edu/x/weeks/5/)
- [Linked List in C](https://www.geeksforgeeks.org/c/linked-list-in-c/)

#### AI usage in this project:

- **Proofreading**: Used to identify typos in filenames and within the README.md file.

- **Quality Assurance**: Used to suggest additional test cases and ensure comprehensive coverage for all functions.

- **Translation**: Assisted in translating documentation and comments from Portuguese to English.

- **Learning**: Used to better understand complex functions through AI-generated examples and visual diagrams.
- **Documentation Organization**: Used to structure and format function tables and project descriptions into clean, readable Markdown.


## Functions Reference

Below is a complete list of the functions implemented in this library, categorized by their original sections in the project subject.

## Part 1 - Libc Functions
Standard C library functions reimplemented with the `ft_` prefix.

| Function | Description |
| :--- | :--- |
| **ft_isalpha** | Checks for an alphabetic character. |
| **ft_isdigit** | Checks for a digit (0 through 9). |
| **ft_isalnum** | Checks for an alphanumeric character. |
| **ft_isascii** | Checks whether `c` fits into the ASCII character set. |
| **ft_isprint** | Checks for any printable character including space. |
| **ft_strlen** | Calculates the length of a string. |
| **ft_memset** | Fills memory with a constant byte. |
| **ft_bzero** | Erases the data in the n bytes of the memory starting at the location pointed to by s by writing zeros. |
| **ft_memcpy** | Copies n bytes from memory area src to memory area dest. The memory areas must not overlap. |
| **ft_memmove** | Copies n bytes from memory area src to memory area dest. The memory areas may overlap. |
| **ft_strlcpy** | Copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result. |
| **ft_strlcat** | Appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result. |
| **ft_toupper** | Converts a lowercase letter to uppercase. |
| **ft_tolower** | Converts an uppercase letter to lowercase. |
| **ft_strchr** | Returns a pointer to the first occurrence of the character c in the string s. |
| **ft_strrchr** | Returns a pointer to the last occurrence of the character c in the string s. |
| **ft_strncmp** | Compares the two strings s1 and s2 up to n characters. |
| **ft_memchr** | Scans the initial n bytes of the memory area pointed to by s for the first instance of c. |
| **ft_memcmp** | Compares the first n bytes of the memory areas s1 and s2. |
| **ft_strnstr** | Locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched. |
| **ft_atoi** | Converts the initial portion of the string pointed to by nptr to int. |
| **ft_calloc** | Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero. |
| **ft_strdup** | Returns a pointer to a new string which is a duplicate of the string s. |

## Part 2 - Additional Functions
Functions that are either not in the libc or are implemented in a different form.

| Function | Description |
| :--- | :--- |
| **ft_substr** | Allocates and returns a substring from the string ’s’. |
| **ft_strjoin** | Allocates and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’. |
| **ft_strtrim** | Allocates and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string. |
| **ft_split** | Allocates and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. |
| **ft_itoa** | Allocates and returns a string representing the integer received as an argument. |
| **ft_strmapi** | Applies the function ’f’ to each character of the string ’s’ to create a new string resulting from successive applications of ’f’. |
| **ft_striteri** | Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument. |
| **ft_putchar_fd** | Outputs the character ’c’ to the given file descriptor. |
| **ft_putstr_fd** | Outputs the string ’s’ to the given file descriptor. |
| **ft_putendl_fd** | Outputs the string ’s’ to the given file descriptor followed by a newline. |
| **ft_putnbr_fd** | Outputs the integer ’n’ to the given file descriptor. |

## Part 3 - Linked List Functions
Functions to manipulate the list structure (`t_list`).

| Function | Description |
| :--- | :--- |
| **ft_lstnew** | Allocates and returns a new node. |
| **ft_lstadd_front** | Adds the node ’new’ at the beginning of the list. |
| **ft_lstsize** | Counts the number of nodes in a list. |
| **ft_lstlast** | Returns the last node of the list. |
| **ft_lstadd_back** | Adds the node ’new’ at the end of the list. |
| **ft_lstdelone** | Takes a node and frees its content using the function ’del’ and then frees the node. |
| **ft_lstclear** | Deletes and frees the given node and every successor of that node, using the function ’del’ and free(3). |
| **ft_lstiter** | Iterates the list ’lst’ and applies the function ’f’ on the content of each node. |
| **ft_lstmap** | Iterates the list ’lst’ and applies the function ’f’ on the content of each node. Creates a new list resulting of the successive applications of the function ’f’. |