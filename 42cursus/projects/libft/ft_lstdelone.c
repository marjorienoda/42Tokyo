/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:51:09 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/07 15:31:57 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_lstdelone frees the content of the node using
 * the function del. Free the node itself but does not free
 * the next node.
 *
 * RETURN VALUE:
 * None
 */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if(!lst || !del)
        return;
    del(lst->content);
    free(lst);
}
