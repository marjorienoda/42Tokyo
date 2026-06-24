/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makrivor <makrivor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:02:46 by makrivor          #+#    #+#             */
/*   Updated: 2026/06/23 18:51:09 by makrivor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	ft_disorder(t_node *stack, t_bench *bench)
{
	int		mistakes;
	int		total_pairs;
	t_node	*current;
	t_node	*next;

	total_pairs = 0;
	mistakes = 0;
	current = stack;
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
	bench->disorder = (double)mistakes / total_pairs;
	return (((double)mistakes / total_pairs));
}
