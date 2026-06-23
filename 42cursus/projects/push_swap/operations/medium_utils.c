/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:02:56 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/23 18:02:58 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_chunk(int size)
{
	int	i;
	int	chunk_size;

	i = 1;
	while (i * i <= size)
		i++;
	chunk_size = i - 1;
	return (chunk_size);
}

static int	find_max_index(t_node **stack_b)
{
	int		max;
	t_node	*current;

	max = (*stack_b)->index;
	current = (*stack_b);
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

static int	find_position(t_node **stack_b, int index)
{
	int		position;
	t_node	*current;

	current = (*stack_b);
	position = 0;
	while (current)
	{
		if (current->index == index)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

void	move_max_to_top(t_node **stack_b, t_bench *bench)
{
	int	max;
	int	pos;
	int	size;

	size = stack_size(*stack_b);
	max = find_max_index(stack_b);
	pos = find_position(stack_b, max);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while ((*stack_b)->index != max)
			rb_op(stack_b, bench);
	}
	else
	{
		while ((*stack_b)->index != max)
		{
			rrb_op(stack_b, bench);
		}
	}
}
