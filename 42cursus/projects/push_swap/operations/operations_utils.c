/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:02 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:52:06 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_op(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	temp->prev = NULL;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	*stack = temp;
}

void	rotate_op(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack);
	last = stack_last(*stack);
	(*stack) = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}

void	reverse_rotate_op(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->next = (*stack);
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

int	find_min_pos(t_node *stack)
{
	int		min_pos;
	int		i;
	long	min;

	i = 0;
	min_pos = 0;
	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((1 << max_bits) < size)
		max_bits++;
	return (max_bits);
}
