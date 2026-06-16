/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:53:16 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:53:17 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_op(t_node **stack_a, t_bench *bench)
{
	swap_op(stack_a);
	if (bench)
		bench->sa_ops++;
	bench->total_ops++;
	ft_printf("sa\n", 1);
}
