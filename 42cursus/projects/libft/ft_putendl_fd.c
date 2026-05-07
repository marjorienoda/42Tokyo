/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:01:37 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:01:40 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_putendl_fd outputs the string s to the
 * specified file descriptor (fd) followed by a newline.
 *
 * RETURN VALUE:
 * None.
 */

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    int i;
    i = 0;

    while(s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
    ft_putchar_fd('\n', 1);
}
