/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 08:15:18 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 08:15:18 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_rev_int_tab(int *tab, int size)
{
    int i;
    int pos;
    int new_arr[size];

    i = 0;
    pos = size;
    while (i < size)
    {
        new_arr[i] = tab[pos];
        i++;
        pos--;
    }
    
    i = 0;
    while (i < size)
    {
        tab[i] = new_arr[i];
        i++;
    }
}

#include <stdio.h>

int main(void)
{
    int array[] = {1, 2, 3, 4};
    int *arry_ptr;
    int i;


    arry_ptr = array;
    ft_rev_int_tab(arry_ptr, 4);
    i = 0;
    while (i < 4)
    {
        printf("%d", array[i]);
    }

    return (0);

}