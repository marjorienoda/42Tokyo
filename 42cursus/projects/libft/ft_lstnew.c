/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:00:21 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:44:11 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_lstnew allocates memory and returns a new node.
 * The content member variable is initialized with the given
 * parameter (content).
 * The variable next is initialized to NULL.
 *
 * RETURN VALUE:
 * The pointer to the new node.
 */

#include "libft.h"


t_list *ft_lstnew(void *content)
{
    t_list *ptr_node;
    ptr_node = malloc(sizeof(t_list));
    if(!ptr_node)
    {
        return(NULL);
    }
    ptr_node->content = content;
    ptr_node->next = NULL;
    return(ptr_node);
}
