*This project has been created as part
of the 42 curriculum by mnoda-ta, makrivor.*

# PUSH_SWAP

## Description
Push_swap is a sorting algorithm project where two stacks and a limited set of operations are used to sort a list of integers with the fewest possible moves. The program reads a list of integers, selects the most efficient sorting strategy based on the initial disorder of the stack, and outputs the sequence of operations to sort it.

## Instructions

### Compilation

The project includes a `Makefile` with the following rules:

| Rule          | Description                                             |
| -----------   | -----------                                             |
| `make`        | Compiles the functions and creates `push_swap`.     |
| `make clean`  | Removes all the object files (.o).                      |
| `make fclean` | Removes all object files and the compiled `push_swap`.|
| `make re`     | Performs a full recompilation (`fclean` + `make`).      |

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] 
```

### Strategy flags

- `--simple` — Forces the O(n²) algorithm
- `--medium` — Forces the O(n√n) algorithm  
- `--complex` — Forces the O(n log n) algorithm
- `--adaptive` — Selects the algorithm based on disorder (default)

### Benchmark mode

```bash
./push_swap --bench --adaptive 4 67 3 87 23 2>bench.txt
```

### Error handling

The program prints `Error` to stderr and exits if:
- An argument is not a valid integer
- A value exceeds INT_MIN or INT_MAX
- Duplicate values are detected

### Verify sorting

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms

### Simple — Min/Max Extraction O(n²)

Triggered by `--simple` and by `--adaptive` when disorder < 0.2.

The algorithm repeatedly finds the minimum element in stack A, rotates the stack to bring it to the top using either `ra` or `rra` — whichever requires fewer moves — and pushes it to stack B. Once only one element remains in A, all elements are pushed back from B to A in sorted order.

This approach is justified for low-disorder inputs because the stack is nearly sorted, meaning the minimum element is likely close to the top, keeping the rotation cost low.

## Contributions

**\<mnoda-ta\> (Marjorie)**
- Main program architecture
- Argument parsing and error handling
- Strategy flag manager
- Benchmark mode
- Simple algorithm
- Doubly linked list implementation
- The 11 push_swap operations

## Resources
- [Stack in C](https://www.geeksforgeeks.org/c/implement-stack-in-c/)
- [Big O definition](https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/)
- [Doubly Linked List](https://www.geeksforgeeks.org/dsa/doubly-linked-list/)
- [Doubly Linked List Tutorial](https://www.geeksforgeeks.org/dsa/doubly-linked-list/)
- [Swap given nodes in a Doubly Linked List without modifying data](https://www.geeksforgeeks.org/dsa/swap-given-nodes-in-a-doubly-linked-list-without-modifying-data/)
- [Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/)
- [When to Prefer Enum Instead of Define in C?](https://www.geeksforgeeks.org/c/when-to-use-enum-instead-of-define-in-c/)
- [Input-output system calls](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)
- [Bucket Sort](https://www.geeksforgeeks.org/dsa/bucket-sort-2/)
- [C exit(), abort() and assert() Functions](https://www.geeksforgeeks.org/c/c-exit-abort-and-assert-functions/)
- man 3 exit - process termination documentation

### AI Usage

Claude was used during this project to:
- Explain and debug the doubly linked list pointer logic for the 11 operations
- Identify performance issues in the sorting algorithm and understand O(n²) vs O(n log n) complexity
- Review code structure and Norm compliance