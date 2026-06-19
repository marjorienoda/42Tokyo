/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:11:04 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/11 12:11:06 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// static void	print_stack(t_node *stack)
// {
// 	t_node	*current;

// 	current = stack;
// 	while (current != NULL)
// 	{
// 		printf("value: %d | index: %d\n", current->value, current->index);
// 		current = current->next;
// 	}
// }

int	main(int argc, char **argv)
{
	int			start;
	int			size;
	t_strategy	flag;
	t_bench		bench;
	t_node		*stack_a;
	t_node		*stack_b;
	int			*array;
	int			chunk_size;

	if (argc < 2)
		return (0);
	is_valid_input(argc, argv);
	start = get_start_pos(argc, argv);
	flag = get_strategy_flag(argc, argv);
	init_bench(&bench, flag);
	stack_a = init_stack_a(argc, argv, start);
	stack_b = NULL;
	size = stack_size(stack_a);
	if (flag == SIMPLE)
		simple_strag(&stack_a, &stack_b, &bench);
	if (is_bench(argc, argv))
		print_bench_mode(&bench);
	array = create_array_tmp(stack_a, size);
	// printf("array created \n");
	array = bubble_sort(array, size);
	// printf("array sorted \n");
	fill_index_stack(stack_a, array, size);
	// printf("stack index fill \n");
	// printf("stack after filling index \n");
	// print_stack(stack_a);
	chunk_size = ft_chunk(size);
	// printf("chunk_size: %d \n", chunk_size);
	chunk_sort(&stack_a, &stack_b, chunk_size, &bench);
	// printf("stack a: \n");
	// print_stack(stack_a);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
