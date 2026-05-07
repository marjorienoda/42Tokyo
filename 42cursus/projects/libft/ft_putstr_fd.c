/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:01:54 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:01:58 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_putstr_fd outputs the string s to the
 * specified file descriptor (fd).
 *
 * RETURN VALUE:
 * None.
 */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    int i;
    i = 0;

    while(s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}
