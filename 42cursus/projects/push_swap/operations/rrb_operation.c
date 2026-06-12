#include "../push_swap.h"

void rrb_op(t_node **stack_b, t_bench *bench)
{
    reverse_rotate_op(stack_b);
    if (bench)
        bench->rrb_ops++;
    bench->total_ops++;
    ft_printf("rrb\n", 1);
}