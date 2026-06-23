/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:32 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:52:34 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_op(t_node **stack_a, t_bench *bench)
{
	rotate_op(stack_a);
	if (bench)
	{
		bench->ra_ops++;
		bench->total_ops++;
	}
	ft_printf("ra\n", 1);
}
