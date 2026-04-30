/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:16:48 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/27 10:17:09 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_strnstr locates the first occurence of the null-terminated
 * string little in the string big, where not more than len charactes are
 * searched.
 *
 * RETURN VALUE:
 * If little is an empty string, big is returned;
 * If little occurs nowhere in big, NULL is returned; otherwise a pointer
 * to the first character of the first occurrence of little is returned.
 */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			if (big[i + j + 1] == '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}
