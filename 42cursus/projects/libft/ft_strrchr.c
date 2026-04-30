/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:44:54 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/24 14:44:56 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_strrchr locates the last occurence of c in the string
 * pointed by s.
 *
 * RETURN VALUE:
 * The pointer of the last occurence of c or a null pointer if c does
 * not occur in the string.
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	size_t		str_len;

	str_len = ft_strlen(s);
	ptr = s + str_len;
	while (ptr >= s)
	{
		if (c == *ptr)
			return ((char *)ptr);
		ptr--;
	}
	return (NULL);
}
