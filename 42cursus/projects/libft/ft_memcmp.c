/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:08:39 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/28 16:50:44 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_memcmp compares the first n bytes of the memory
 * areas s1 e s2.
 *
 * RETURN VALUE:
 * - An integer less than, equal to, or greater than zero if the first
 * n bytes of s1 is found, respectively, to be less than, to match,
 * or be greater than the first n bytes of s2.
 * - For a nonzero return value, the sign is determined by the sign of
 * the difference between the first pair of bytes (interpreted as
 * unsigned char) that differ in s1 and s2.
 * - If n is zero, the return value is zero.
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
