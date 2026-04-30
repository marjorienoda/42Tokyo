/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:17:02 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/24 17:42:47 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_isalpha checks if the parameter is an
 * alphabetic character or not.
 *
 * RETURN VALUE:
 * 1 if the character c is an alphabetic charater, zero if is not.
 */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' || c <= 'Z') && (c >= 'a' || c <= 'z'))
		return (1);
	return (0);
}
