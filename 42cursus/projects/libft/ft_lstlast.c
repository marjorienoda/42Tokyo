/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:30:22 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/08 14:30:24 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_lstlast returns the last node of the list.
 *
 * RETURN VALUE:
 * The pointer to last node of the list.
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
	{
		return (NULL);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}
