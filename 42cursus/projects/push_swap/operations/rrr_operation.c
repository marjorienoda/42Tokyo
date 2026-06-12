#include "../push_swap.h"

void rrr_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
    rra_op(stack_a);
    rrb_op(stack_b);
    if (bench)
        bench->rrr_ops++;
    bench->total_ops++;
    ft_printf("rrr\n", 1);
}