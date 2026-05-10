/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:26:26 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/08 14:26:54 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION:
 * The function ft_lstclear deletes and frees the given node and all
 * its successors, using the function del and free(3).
 * Set the pointer to the list to NULL.
 *
 * RETURN VALUE:
 * None
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_ptr;

	while (*lst)
	{
		temp_ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp_ptr;
	}
	*lst = NULL;
}
