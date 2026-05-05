/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:04:20 by marjorie          #+#    #+#             */
/*   Updated: 2026/05/05 12:17:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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