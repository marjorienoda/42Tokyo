*This project has been created as part of the 42 curriculum by mnoda-ta.*

## Description

Get Next Line is a function that reads a line from a file descriptor, one line at a time.
The function can be called repeatedly to read an entire file line by line, and works both
with files and standard input. The key concept learned in this project is the use of
static variables in C, which allow the function to remember its state between calls.

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

The `BUFFER_SIZE` can be any positive integer:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c
```

### Usage

```c
int     fd;
char    *line;

fd = open("file.txt", O_RDONLY);
while (1)
{
    line = get_next_line(fd);
    if (line == NULL)
        break ;
    printf("%s", line);
    free(line);
}
close(fd);
```

## Algorithm

The algorithm uses a static variable `bucket` that persists between calls to store
leftover data from previous reads.

Each call to `get_next_line` follows three steps:

1. **read_line** — reads from the file descriptor in chunks of `BUFFER_SIZE` bytes,
appending each chunk to `bucket` until a newline is found or EOF is reached.
To avoid O(n²) performance, the length of `bucket` is tracked in a variable
`bucket_len` that is incremented by `bytes_read` each iteration, instead of
recalculating with `ft_strlen` every time.

2. **extract_line** — extracts the first line (up to and including the `\n`) from
`bucket` and returns it.

3. **update_bucket** — removes the extracted line from `bucket`, keeping the
remainder for the next call.

## Resources

- `man 2 read` — read() system call documentation
- `man 3 malloc` — memory allocation documentation
- `man 3 strlen` — calculation of the lenght of a string documentation
- [Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Buffer in C Programming](https://www.geeksforgeeks.org/c/buffer-in-c-programming/)
- [Input-output system calls](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)

### AI Usage

Claude was used during this project to:
- Explain a performance issue (O(n²) complexity) caused by calling
`ft_strlen` on the growing bucket at every iteration
- Understand the difference between passing a value and passing a pointer (`&`) 
when a function needs to modify a variable in the caller
- Review the code against the subject requirements