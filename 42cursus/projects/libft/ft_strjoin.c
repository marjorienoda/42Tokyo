/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:15:57 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/30 14:47:34 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_strjoin allocates memory (using malloc(3))
 * and returns a new string, which is the result of concatenating s1 and s2.
 *
 * RETURN VALUE:
 * The pointer of the new string.
 * NULL if the allocation fails.
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	ptr[s1_len + s2_len] = '\0';
	return (ptr);
}
