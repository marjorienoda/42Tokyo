/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:15:47 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:00:57 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_memset fills the first n bytes of the memory area
 * pointed to by s with c.
 *
 * RETURN VALUE:
 * A pointer to the memory area s.
 */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	ch = (unsigned char)c;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = ch;
		i++;
	}
	return (s);
}
