/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:40 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:52:42 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb_op(t_node **stack_b, t_bench *bench)
{
	rotate_op(stack_b);
	if (bench)
	{
		bench->rb_ops++;
		bench->total_ops++;
	}
	ft_printf("rb\n", 1);
}
