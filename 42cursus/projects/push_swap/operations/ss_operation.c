/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:08:05 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/23 16:25:51 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	swap_op(stack_a);
	swap_op(stack_b);
	if (bench)
	{
		bench->ss_ops++;
		bench->total_ops++;
	}
	ft_printf("ss\n", 1);
}
