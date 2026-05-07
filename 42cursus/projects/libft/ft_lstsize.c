/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:00:39 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:00:43 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_lstsize counts the number of nodes in the list.
 *
 * RETURN VALUE:
 * The lenght of the list.
 */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int count;

    count = 0;
    while(lst != NULL)
    {
        count++;
        lst = lst->next;
    }
    return(count);
}
