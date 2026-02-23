/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-11 03:18:45 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-11 03:18:45 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	lenght_str;

	lenght_str = 0;
	while (*str != '\0')
	{
		lenght_str++;
		str++;
	}
	return (lenght_str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char string[] = "!Marjorie !";
// 	char *string_ptr = string;

// 	printf("%d", ft_strlen(string_ptr));
// 	return (0);
// }