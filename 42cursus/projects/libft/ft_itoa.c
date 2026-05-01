/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:51:47 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/01 17:12:32 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_itoa allocates memory (using malloc(3))
 * and returns a string representing the integer received as an
 * argument.
 *
 * RETURN VALUE:
 * The pointer to string.
 * NULL if the allocation fails.
 */

#include "libft.h"
#include <stdio.h>

static int	ft_nb_len(int n)
{
	long	nb;
	int		len;

	nb = (long)n;
	len = 1;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = (long)n;
	len = ft_nb_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
