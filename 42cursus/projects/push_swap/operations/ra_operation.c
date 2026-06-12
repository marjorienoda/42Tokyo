#include "../push_swap.h"

void ra_op(t_node **stack_a, t_bench *bench)
{
    rotate_op(stack_a);
    if (bench)
        bench->ra_ops++;
    bench->total_ops++;
    ft_printf("ra\n", 1);
}