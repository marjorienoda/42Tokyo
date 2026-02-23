/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 07:17:22 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/22 16:30:30 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
    char c;

    c = '0';
    while (c <= '9')
    {
	    write(1, &c, 1);
	    c++;
    }
}

// int main(void)
// {
//     ft_print_numbers();
//     return(0);
// }
