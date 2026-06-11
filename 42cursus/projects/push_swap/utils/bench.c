/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:10:37 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/11 12:10:39 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_bench(t_bench *bench, t_strategy flag)
{
	bench->disorder = 0.02;
	bench->strategy_flag = flag;
	bench->actual_flag = flag;
	bench->total_ops = 0;
	bench->sa_ops = 0;
	bench->sb_ops = 0;
	bench->ss_ops = 0;
	bench->pa_ops = 0;
	bench->pb_ops = 0;
	bench->ra_ops = 0;
	bench->rb_ops = 0;
	bench->rr_ops = 0;
	bench->rra_ops = 0;
	bench->rrb_ops = 0;
	bench->rrr_ops = 0;
}

static char	*print_strategy(t_bench *bench)
{
	char	*strategy_name;

	strategy_name = NULL;
	if (bench->strategy_flag == SIMPLE)
		strategy_name = "Simple  O(n²)";
	else if (bench->strategy_flag == MEDIUM)
		strategy_name = "Medium O(n√n)";
	else if (bench->strategy_flag == COMPLEX)
		strategy_name = "Complex O(n log n)";
	else if (bench->strategy_flag == ADAPTIVE)
	{
		if (bench->actual_flag == SIMPLE)
			strategy_name = "Adapative / O(n²)";
		else if (bench->actual_flag == MEDIUM)
			strategy_name = "Adapative / O(n√n)";
		else if (bench->actual_flag == COMPLEX)
			strategy_name = "Adapative / O(n log n)";
		else
			strategy_name = "Adapative / O(n log n)";
	}
	return (strategy_name);
}

void	print_bench_mode(t_bench *bench)
{
	ft_printf("[bench] disorder: %f%%\n", 2, bench->disorder);
	ft_printf("[bench] strategy: %s\n", 2, print_strategy(bench));
	ft_printf("[bench] total_ops: %d\n", 2, bench->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", 2, bench->sa_ops,
		bench->sb_ops, bench->ss_ops, bench->pa_ops, bench->pb_ops);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 2,
		bench->ra_ops, bench->rb_ops, bench->rr_ops, bench->rra_ops,
		bench->rrb_ops, bench->rrr_ops);
}
