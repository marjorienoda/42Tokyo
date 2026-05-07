/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 07:52:26 by marvin            #+#    #+#             */
/*   Updated: 2026/05/07 07:52:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *temp_ptr;

    if(!*lst || !lst)
        return;
    while(*lst)
    {
        temp_ptr = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = temp_ptr;
    }
    *lst = NULL;
}
