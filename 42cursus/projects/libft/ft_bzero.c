/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:59:32 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/27 14:50:19 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_bzero erases the data in the n bytes of the memory
 * starting at the location pointed by s, by writing bytes containing '\0'.
 *
 * RETURN VALUE:
 * None.
 */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	i = 0;
	ch = s;
	while (i < n)
	{
		*ch = '\0';
		ch++;
		i++;
	}
}
