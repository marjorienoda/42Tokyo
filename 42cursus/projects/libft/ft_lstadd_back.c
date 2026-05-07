/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:58:18 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:27:11 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_lstadd_back adds the node new at the end
 * of the list.
 *
 * RETURN VALUE:
 * None
 */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    new-> next = NULL;
    if(*lst == NULL)
    {
        *lst = new;
        return;
    }
    last = ft_lstlast(*lst);
    last-> next = new;
}
