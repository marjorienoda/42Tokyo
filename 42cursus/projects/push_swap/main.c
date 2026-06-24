/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makrivor <makrivor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:11:04 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/23 18:52:54 by makrivor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_flag(t_strategy flag, t_node **stack_a, t_node **stack_b,
		t_bench *bench)
{
	if (flag == SIMPLE)
		simple_strag(stack_a, stack_b, bench);
	else if (flag == MEDIUM)
		medium_strag(stack_a, stack_b, bench);
	else if (flag == COMPLEX)
		complex_strag(stack_a, stack_b, bench);
	else if (flag == ADAPTIVE)
		adaptive_strag(stack_a, stack_b, bench);
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
	bench.disorder = ft_disorder(stack_a);
	if(bench.disorder > 0)
		run_flag(flag, &stack_a, &stack_b, &bench);
	if (is_bench(argc, argv))
		print_bench_mode(&bench);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
