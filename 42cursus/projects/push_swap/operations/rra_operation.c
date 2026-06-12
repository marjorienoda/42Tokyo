#include "../push_swap.h"

void rra_op(t_node **stack_a, t_bench *bench)
{
    reverse_rotate_op(stack_a);
    if (bench)
        bench->rra_ops++;
    bench->total_ops++;
    ft_printf("rra\n", 1);
}