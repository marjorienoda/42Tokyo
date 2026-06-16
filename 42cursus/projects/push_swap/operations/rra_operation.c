/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:56 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:52:58 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_op(t_node **stack_a, t_bench *bench)
{
	reverse_rotate_op(stack_a);
	if (bench)
		bench->rra_ops++;
	bench->total_ops++;
	ft_printf("rra\n", 1);
}
