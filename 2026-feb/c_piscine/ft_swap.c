/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 07:52:44 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 07:52:44 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap(int *a, int *b)
{
    int nb;
    int nb1;

    nb = *a;
    nb1 = *b;

    *a = nb1;
    *b = nb;
}

#include <stdio.h>

int main (void)
{
    int nb = 6;
    int nb1 = 5;
    int *nbptr;
    int *nb1ptr;

    nbptr = &nb;
    nb1ptr = &nb1;

    ft_swap(nbptr, nb1ptr);
    printf("%d \n", nb);
    printf("%d", nb1);
    return (0);
}