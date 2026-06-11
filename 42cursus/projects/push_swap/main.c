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

int	main(int argc, char **argv)
{
	int			start;
	t_strategy	flag;
	t_bench		bench;

	// int bench_flg;
	if (argc < 2)
		return (0);
	is_valid_input(argc, argv);
	start = get_start_pos(argc, argv);
	flag = get_strategy_flag(argc, argv);
	// bench_flg = is_bench(argc, argv);
	init_bench(&bench, get_strategy_flag(argc, argv));
	printf("start: %d \n", start);
	printf("flag: %d \n", flag);
	// printf("bench: %d \n", bench_flg);
	// printf("disorder: %f\n", bench.disorder);
	// printf("total_ops: %d\n", bench.total_ops);
	print_bench_mode(&bench);
	return (0);
}
