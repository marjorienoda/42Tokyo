/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:53:01 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:53:03 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb_op(t_node **stack_b, t_bench *bench)
{
	reverse_rotate_op(stack_b);
	if (bench)
	{
		bench->rrb_ops++;
		bench->total_ops++;
	}
	ft_printf("rrb\n", 1);
}
