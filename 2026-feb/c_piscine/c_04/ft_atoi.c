/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:21:31 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/15 09:27:19 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_first_char(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	return (str);
}

int	ft_number_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	long	nb;
	int		sign;
	char	*str_ptr;

	str_ptr = ft_first_char(str);
	nb = 0;
	sign = ft_number_sign(str_ptr);
	while (*str_ptr == '-' || *str_ptr == '+')
	{
		str_ptr++;
	}
	while (*str_ptr >= '0' && *str_ptr <= '9')
	{
		nb = nb * 10 + (*str_ptr - '0');
		str_ptr++;
	}
	return (nb * sign);
}

// #include <stdio.h>

// int		ft_atoi(char *str);

// void	run_test(char *input, int expected)
// {
// 	int	result;

// 	result = ft_atoi(input);
// 	printf("Input: [%s]\n", input);
// 	printf("Expected: %d | Result: %d\n", expected, result);
// 	if (result == expected)
// 	{
// 		printf("STATUS: SUCCESS ✅\n");
// 	}
// 	else
// 	{
// 		printf("STATUS: FAIL ❌\n");
// 	}
// 	printf("---------------------------------------\n");
// }

// int	main(void)
// {
// 	printf("--- Starting ft_atoi Tests ---\n\n");

// 	// Requirement: Basic conversion
// 	run_test("1234", 1234);

// 	// Requirement: Arbitrary whitespace
// 	run_test("   \t\n\v\f\r 42", 42);

// 	// Requirement: Multiple signs (Even '-' = Positive)
// 	run_test("---++--42", -42);
// 	run_test("--++--42", 42);

// 	// Requirement: Provided Example
// 	run_test(" ---+--+1234ab567", -1234);

// 	// Requirement: Stop at non-conforming character
// 	run_test("42sh42", 42);
// 	run_test("-00123.456", -123);

// 	// Edge Case: No digits at all
// 	run_test("  ---++  123", 0);
// 	run_test("abc123", 0);

// 	// Edge Case: Zeroes
// 	run_test("  +---0000042", -42);

// 	return (0);
// }