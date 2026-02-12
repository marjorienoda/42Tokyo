int ft_fibonacci(int index)
{
    if (index == 0)
    {
        return (0);
    }
    if (index < 0)
    {
        return (-1);
    }
    if (index == 1)
    {
        return (1);
    }
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

#include <stdio.h>

// Prototype
int ft_fibonacci(int index);

void run_test(int index, int expected) {
    int result = ft_fibonacci(index);
    if (result == expected) {
        printf("[PASS] Index: %d | Expected: %d | Result: %d\n", index, expected, result);
    } else {
        printf("[FAIL] Index: %d | Expected: %d | Result: %d\n", index, expected, result);
    }
}

int main(void) {
    printf("--- Starting Fibonacci Tests ---\n\n");

    // Requirement: If index < 0, return -1
    printf("Testing Error Handling:\n");
    run_test(-1, -1);
    run_test(-42, -1);

    // Requirement: First element (0) is 0, second (1) is 1
    printf("\nTesting Base Cases:\n");
    run_test(0, 0);
    run_test(1, 1);

    // Testing Sequence Progressions
    printf("\nTesting Sequence Progression:\n");
    run_test(2, 1);
    run_test(3, 2);
    run_test(4, 3);
    run_test(5, 5);
    run_test(6, 8);
    run_test(9, 34); // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

    printf("\n--- Tests Complete ---\n");
    return 0;
}