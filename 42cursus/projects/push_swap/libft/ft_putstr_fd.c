/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:09:28 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/11 12:09:30 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if(!s)
		return(0);
	while (s[i] != '\0')
	{
		counter += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (counter);
}
