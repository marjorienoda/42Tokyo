/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-11 03:26:16 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-11 03:26:16 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

// int	main(void)
// {
// 	char string[] = "Hello!";
// 	char *string_ptr;

// 	string_ptr = string;
// 	ft_putstr(string_ptr);
// 	return (0);
// }