#include "../push_swap.h"

void rr_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
    ra_op(stack_a, bench);
    rb_op(stack_b, bench);
    if (bench)
        bench->rr_ops++;
    bench->total_ops++;
    ft_printf("rr\n", 1);
}