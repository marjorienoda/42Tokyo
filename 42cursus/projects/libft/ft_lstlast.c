/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:24:38 by marvin            #+#    #+#             */
/*   Updated: 2026/05/05 13:24:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
   t_list *current;
   current = lst;
   if(current == NULL)
   {
    return (NULL);
   }
   while(current->next != NULL)
   {
    current = current->next;
   }
   return(current);
}