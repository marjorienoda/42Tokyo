/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:12:40 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/28 11:27:59 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_memmove copies n bytes from memory area src to memory dest.
 * The memory areas may overlap.
 *
 * RETURN VALUE:
 * The pointer to dest.
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_s;
	const unsigned char	*src_s;

	if (!dest && !src)
		return (NULL);
	dest_s = (unsigned char *)dest;
	src_s = (const unsigned char *)src;
	if (dest_s < src_s)
		while (n--)
			*dest_s++ = *src_s++;
	else
	{
		dest_s += n;
		src_s += n;
		while (n--)
			*(--dest_s) = *(--src_s);
	}
	return (dest);
}
