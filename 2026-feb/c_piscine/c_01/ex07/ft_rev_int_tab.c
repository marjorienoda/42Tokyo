/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:39:40 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/07 14:39:40 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_rev_int_tab(int *tab, int size)
{
    int position = 0;
    int position_rev = size;
    int second_array_counter = 0;
    int array_rev[size];

    tab = tab + size - 1;
    while(position_rev > 0)
    {
        array_rev[position] = *tab;
        tab--;
        position++;
        position_rev--;
    }
    tab++;

    while(second_array_counter < size)
    {
        *tab = array_rev[second_array_counter];
        tab++;
        second_array_counter++;
    }
    tab = tab - (size - 1);
}