/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makrivor <makrivor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:02:46 by makrivor          #+#    #+#             */
/*   Updated: 2026/06/23 18:03:01 by makrivor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	ft_disorder(t_node *stack)
{
	int		mistakes;
	int		total_pairs;
	t_node	*current;
	t_node	*next;

	total_pairs = 0;
	mistakes = 0;
	current = stack->prev;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->value > next->value)
				mistakes++;
			total_pairs++;
			next = next->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0f);
	return (((float)mistakes / total_pairs));
}
