/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 08:11:10 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 08:11:10 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

// #include <stdio.h>

// int main(void)
// {
//     char str[] = "Marjorie 9292020";
//     char *strptr;

//     strptr = str;
//     printf("%d", ft_strlen(strptr));
//     return (0);
// }