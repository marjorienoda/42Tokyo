/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makrivor <makrivor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:15 by makrivor          #+#    #+#             */
/*   Updated: 2026/06/19 15:51:15 by makrivor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// chunk number calc
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

// void	assign_indexes(t_node *stack_a, int *sorted_arr, int size)
// {
// 	t_node	*current;
// 	int		i;

// 	current = stack_a->prev;
// 	while (current != NULL)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			if (current->value == sorted_arr[i])
// 			{
// 				current->index = i;
// 				break ;
// 			}
// 			i++;
// 		}
// 		current = current->next;
// 	}
// }

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

static void	move_max_to_top(t_node **stack_b, t_bench *bench)
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

void	push_chunks(t_node **a, t_node **b, int chunk_size, t_bench *bench)
{
	int	chunk_min;
	int	chunk_max;
	int	pushed;
	int	i;
	int	initial_size;

	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (*a && stack_size(*a) > 1)
	{
		pushed = 0;
		i = 0;
		initial_size = stack_size(*a);
		while (i < initial_size && pushed < chunk_size)
		{
			if ((*a)->index >= chunk_min && (*a)->index <= chunk_max)
			{
				pb_op(a, b, bench);
				pushed++;
				if ((*b)->index < (chunk_max - chunk_size / 2))
					rb_op(b, bench);
			}
			else
				ra_op(a, bench);
			i++;
		}
		chunk_min += chunk_size;
		chunk_max += chunk_size;
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

void	chunk_sort(t_node **a, t_node **b, int chunk_size, t_bench *bench)
{
	push_chunks(a, b, chunk_size, bench);
	restore_stack(a, b, bench);
}

// sa (swap a): Swap the first two elements at the top of stack a.
// Do nothing if there is only one or no elements.

// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by one.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by one.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.
// rrr : rra and rrb at the same tim