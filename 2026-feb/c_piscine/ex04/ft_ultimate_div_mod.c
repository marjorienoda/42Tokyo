/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 08:03:29 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 08:03:29 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_ultimate_div_mod(int *a, int *b)
{
    int div;
    int mod;

    div = *a / *b;
    mod = *a % *b;

    *a = div;
    *b = mod;
}

#include <stdio.h>

int main(void)
{
    int a = 149;
    int b = 10;
    int *aptr;
    int *bptr;

    aptr = &a;
    bptr = &b;

    ft_ultimate_div_mod(aptr, bptr);
    printf("%d \n", a);
    printf("%d \n", b);
    return (0);
}