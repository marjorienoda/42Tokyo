/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:00:02 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:39:25 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_lstmap iterates through the list lst, applies
 * the function f to each node's content, and creates a new list
 * of the successive applications of the function f.
 * The del function is used to delete the content of a node if
 * needed.
 *
 * RETURN VALUE:
 * The pointer to the new list.
 * NULL if the allocation fails.
 */

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
