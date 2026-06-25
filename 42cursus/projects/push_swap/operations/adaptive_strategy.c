/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makrivor <makrivor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:16:46 by makrivor          #+#    #+#             */
/*   Updated: 2026/06/23 18:51:32 by makrivor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_strag(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	if (bench->disorder < 0.2)
	{
		bench->actual_flag = SIMPLE;
		simple_strag(stack_a, stack_b, bench);
	}
	else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
	{
		bench->actual_flag = MEDIUM;
		medium_strag(stack_a, stack_b, bench);
	}
	else
	{
		bench->actual_flag = COMPLEX;
		complex_strag(stack_a, stack_b, bench);
	}
}