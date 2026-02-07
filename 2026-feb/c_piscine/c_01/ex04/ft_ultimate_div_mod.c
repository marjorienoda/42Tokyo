/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:03:20 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/07 12:03:20 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void ft_ultimate_div_mod(int *a, int *b)
{
    int div_result = *a / *b;
    int mod_result = *a % *b;

    *a = div_result;
    *b = mod_result;
}