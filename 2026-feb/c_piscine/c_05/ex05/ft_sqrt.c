unsigned int ft_power2(int x)
{
    return (x * x);
}

int ft_sqrt(int nb)
{
    int i;

    if (nb <= 0)
    {
        return (0);
    }

    i = 1;
    while (ft_power2(i) != (unsigned) nb && ft_power2(i) < (unsigned) nb)
    {
        i++;
    }

    if (ft_power2(i) == (unsigned) nb) {
        return i;
    }

    return 0;
}

// #include <stdio.h>

// // Prototype of the function to be tested
// int ft_sqrt(int nb);

// void run_test(int input, int expected) {
//     int result = ft_sqrt(input);
//     if (result == expected) {
//         printf("[PASS] nb: %11d | Expected: %5d | Result: %5d\n", input, expected, result);
//     } else {
//         printf("[FAIL] nb: %11d | Expected: %5d | Result: %5d\n", input, expected, result);
//     }
// }

// int main(void) {
//     printf("--- Starting ft_sqrt Tests ---\n\n");

//     printf("Testing Perfect Squares:\n");
//     run_test(1, 1);
//     run_test(4, 2);
//     run_test(9, 3);
//     run_test(25, 5);
//     run_test(100, 10);
//     run_test(2147395600, 46340); // Max possible square for 32-bit int

//     printf("\nTesting Non-Perfect Squares (Irrational -> return 0):\n");
//     run_test(2, 0);
//     run_test(3, 0);
//     run_test(5, 0);
//     run_test(15, 0);
//     run_test(2147483647, 0); // Max int

//     printf("\nTesting Edge Cases & Negatives:\n");
//     run_test(0, 0);
//     run_test(-1, 0);
//     run_test(-25, 0);
//     run_test(-2147483648, 0); // Min int

//     printf("\n--- Tests Complete ---\n");
//     return 0;
// }