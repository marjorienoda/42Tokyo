/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:53:21 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:53:23 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb_op(t_node **stack_b, t_bench *bench)
{
	swap_op(stack_b);
	if (bench)
		bench->sb_ops++;
	bench->total_ops++;
	ft_printf("sb\n", 1);
}
