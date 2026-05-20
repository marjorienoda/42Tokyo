/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:12:50 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/14 12:12:52 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		counter += ft_putchar(s[i]);
		i++;
	}
	return (counter);
}
