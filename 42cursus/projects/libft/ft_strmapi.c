/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:04:27 by marjorie          #+#    #+#             */
/*   Updated: 2026/05/03 13:04:33 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *ptr;
    unsigned int str_len;
    unsigned int i;

    if (!s || !f)
		return (NULL);
    str_len = ft_strlen(s);
    ptr = malloc(sizeof(char) * (str_len + 1));
    if(!ptr)
        return(NULL);
    i = 0;
    while(s[i] != '\0')
    {
        ptr[i] = f(i, s[i]);
        i++;
    }
    ptr[i] = '\0';
    return(ptr);
}
