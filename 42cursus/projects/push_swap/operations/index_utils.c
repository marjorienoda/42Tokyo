/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:50:32 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/19 15:50:33 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*create_array_tmp(t_node *stack_a, int size)
{
	int		*array_tmp;
	int		i;
	t_node	*current;

	array_tmp = malloc(sizeof(int) * size);
	if (!array_tmp)
		return (NULL);
	current = stack_a;
	i = 0;
	while (current != NULL)
	{
		array_tmp[i] = current->value;
		i++;
		current = current->next;
	}
	return (array_tmp);
}

void	swap(int *prev, int *next)
{
	int	tmp;

	tmp = *prev;
	*prev = *next;
	*next = tmp;
}

int	*bubble_sort(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
	return (array);
}

void	fill_index_stack(t_node *stack_a, int *array, int size)
{
	int		i;
	t_node	*current;

	current = stack_a;
	i = 0;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == array[i])
				current->index = i;
			i++;
		}
		current = current->next;
	}
}
