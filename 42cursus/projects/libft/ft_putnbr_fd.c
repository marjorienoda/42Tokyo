/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:36:18 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/08 14:36:22 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_putnbr_fd outputs the integer n to the
 * specified file descriptor (fd).
 *
 * RETURN VALUE:
 * None.
 */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	div;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	div = 1;
	while (nb / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		ft_putchar_fd((nb / div % 10) + '0', fd);
		div = div / 10;
	}
}
