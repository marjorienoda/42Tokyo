/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:52:40 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/28 17:25:18 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_strdup duplicates a string.
 *
 * RETURN VALUE:
 * A pointer to a null-terminated byte string.
 */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	total_len;

	total_len = ft_strlen(s) + 1;
	ptr = malloc(total_len * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, total_len);
	return (ptr);
}
