/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:51:45 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/28 15:43:58 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_memcpy copies n bytes from memory area src to memory dest.
 * The memory areas must not overlap.
 *
 * RETURN VALUE:
 * The pointer to dest.
 */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_s;
	const unsigned char	*src_s;
	size_t				i;

	dest_s = (unsigned char *)dest;
	src_s = (const unsigned char *)src;
	if (!dest && !src_s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest_s[i] = src_s[i];
		i++;
	}
	return (dest);
}
