/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makrivor <makrivor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:15 by makrivor          #+#    #+#             */
/*   Updated: 2026/06/23 17:57:47 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	process_chunk(t_node **a, t_node **b, t_chunk *chunk,
		t_bench *bench)
{
	int	initial_size;
	int	pushed;
	int	i;

	initial_size = stack_size(*a);
	pushed = 0;
	i = 0;
	while (i < initial_size && pushed < chunk->size)
	{
		if ((*a)->index >= chunk->min && (*a)->index <= chunk->max)
		{
			pb_op(a, b, bench);
			if ((*b)->index < (chunk->max - chunk->size / 2))
				rb_op(b, bench);
			pushed++;
		}
		else
			ra_op(a, bench);
		i++;
	}
}

void	push_chunks(t_node **a, t_node **b, int chunk_size, t_bench *bench)
{
	t_chunk	chunk;

	chunk.min = 0;
	chunk.max = chunk_size - 1;
	chunk.size = chunk_size;
	while (*a && stack_size(*a) > 1)
	{
		process_chunk(a, b, &chunk, bench);
		chunk.min += chunk_size;
		chunk.max += chunk_size;
	}
}

static void	restore_stack(t_node **a, t_node **stack_b, t_bench *bench)
{
	while ((*stack_b))
	{
		move_max_to_top(stack_b, bench);
		pa_op(a, stack_b, bench);
	}
}

void	medium_strag(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	chunk_size;
	int	*tmp_array;

	size = stack_size(*a);
	tmp_array = create_array_tmp(*a, size);
	tmp_array = bubble_sort(tmp_array, size);
	fill_index_stack(*a, tmp_array, size);
	free(tmp_array);
	chunk_size = ft_chunk(size);
	push_chunks(a, b, chunk_size, bench);
	restore_stack(a, b, bench);
}
