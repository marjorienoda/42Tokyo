/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 08:07:52 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 08:07:52 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(void)
{
    char str[] = "Hello!";
    char *strptr;

    strptr = str;
    ft_putstr(strptr);
    return (0);
}