/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 07:58:45 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 07:58:45 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

// #include <stdio.h>

// int main(void)
// {
//     int a = 25;
//     int b = 5;
//     int div_result = 0;
//     int mod_result = 0;
//     int *div;
//     int *mod;

//     div = &div_result;
//     mod = &mod_result;

//     ft_div_mod(a, b, div, mod);
//     printf("%d \n", div_result);
//     printf("%d \n", mod_result);
//     return (0);
// }