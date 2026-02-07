/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:56:26 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/07 11:56:26 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_div_mod(int a, int b, int *div, int *mod)
{
    int div_result = a / b;
    int mod_result = a % b;

    *div = div_result;
    *mod = mod_result;
}