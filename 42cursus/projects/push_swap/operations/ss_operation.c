#include "../push_swap.h"

void ss_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
    sa_op(stack_a, bench);
    sb_op(stack_b, bench);
    ft_printf("ss\n", 1);
}