/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:53:10 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:53:12 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	rra_op(stack_a, bench);
	rrb_op(stack_b, bench);
	if (bench)
	{
		bench->rrr_ops++;
		bench->total_ops++;
	}
	ft_printf("rrr\n", 1);
}
