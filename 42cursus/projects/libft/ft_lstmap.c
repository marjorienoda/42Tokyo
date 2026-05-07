/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:35:05 by marvin            #+#    #+#             */
/*   Updated: 2026/05/07 10:35:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst;
    t_list *new_node;
    void *content;

    if(!lst || !f || !del)
        return(NULL);
    new_lst = NULL;
    while(lst)
    {
        content = f(lst->content);
        new_node = ft_lstnew(content);
        if(!new_node)
        {
            del(content);
            ft_lstclear(&new_lst, del);
            return(NULL);
        }
        ft_lstadd_back(&new_lst, new_node);
        lst = lst->next;
    }
    return(new_lst);
}