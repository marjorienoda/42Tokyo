/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:56:51 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/28 17:36:54 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_calloc allocates memory for an array of nmemb elements
 * of size bytes each.
 * The memory is set to zero.
 * If nmemb or size is 0, then the function returns a unique pointer
 * value that can later be successfully passed to free().
 *
 * RETURN VALUE:
 * A pointer to the allocated memory.
 * On error, return NULL.
 */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
