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

// static void print_stack(t_node *stack)
// {
//     t_node *current;

//     current = stack;
//     while (current != NULL)
//     {
//         printf("value: %d | index: %d \n",
//             current->value,
//             current->index);
//         current = current->next;
//     }
// }

// static void print_array(int size, int *array)
// {
// 	int i;

// 	i = 0;
// 	while(i < size)
// 	{
// 		printf("%d \n", array[i]);
// 		i++;
// 	}
// }

static void run_flag(t_node **stack_a, t_node **stack_b, t_bench *bench, t_strategy flag)
{
	if (flag == SIMPLE)
		simple_strag(stack_a, stack_b, bench);
	else if (flag == COMPLEX)
		complex_strag(stack_a, stack_b, bench);
}

int	main(int argc, char **argv)
{
	int			start;
	t_strategy	flag;
	t_bench		bench;
	t_node		*stack_a;
	t_node		*stack_b;

	if (argc < 2)
		return (0);
	is_valid_input(argc, argv);
	start = get_start_pos(argc, argv);
	flag = get_strategy_flag(argc, argv);
	init_bench(&bench, flag);
	stack_a = init_stack_a(argc, argv, start);
	stack_b = NULL;
	run_flag(&stack_a, &stack_b, &bench, flag);
	if (is_bench(argc, argv))
		print_bench_mode(&bench);
	// print_stack(stack_a);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
