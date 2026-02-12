int ft_recursive_power(int nb, int power)
{

    if (power == 0 || nb == 1)
    {
        return (1);
    }
    if (power < 0)
    {
        return (0);
    }
    return nb * ft_recursive_power(nb, power - 1);

}

// #include <stdio.h>
// int ft_recursive_power(int nb, int power);

// int main(void)
// {
//     printf("--- Basic Tests ---\n");
//     printf("2^3  | Expected: 8  | Result: %d\n", ft_recursive_power(2, 3));
//     printf("5^2  | Expected: 25 | Result: %d\n", ft_recursive_power(5, 2));
//     printf("3^4  | Expected: 81 | Result: %d\n", ft_recursive_power(3, 4));

//     printf("\n--- Edge Cases ---\n");
//     printf("10^0 | Expected: 1  | Result: %d\n", ft_recursive_power(10, 0));
//     printf("0^0  | Expected: 1  | Result: %d\n", ft_recursive_power(0, 0));
//     printf("0^5  | Expected: 0  | Result: %d\n", ft_recursive_power(0, 5));
//     printf("1^10 | Expected: 1  | Result: %d\n", ft_recursive_power(1, 10));

//     printf("\n--- Negative Power ---\n");
//     printf("2^-2 | Expected: 0  | Result: %d\n", ft_recursive_power(2, -2));

//     return (0);
// }
