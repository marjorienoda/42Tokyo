/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:16:17 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/28 15:07:05 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_memchr locates the first occurrence of a character c
 * (converted to an unsigned char) in the first n bytes of the memory
 * area pointed to by s.
 *
 * RETURN VALUE:
 * If the character c is found, returns a pointer to the byte located,
 * or, NULL if the character c does not occur.
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		ch;
	size_t				i;

	src = (const unsigned char *)s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (src[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
