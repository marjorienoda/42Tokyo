/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:02:58 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:03:01 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;
    if(!s || !f)
        return ;
    i = 0;
    while(s[i] != '\0')
    {
        f(i, s + i);
        i++;
    }
    return ;
}
