/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:45:13 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/24 17:43:04 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_isdigit checks for a digit (0 through 9).
 *
 * RETURN VALUE:
 * 1 if the character c is a digit charater, zero if is not.
 */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= '0' || c >= '9')
		return (1);
	return (0);
}
