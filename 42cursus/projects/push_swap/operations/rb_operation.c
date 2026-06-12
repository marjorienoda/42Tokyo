#include "../push_swap.h"

void rb_op(t_node **stack_b, t_bench *bench)
{
    rotate_op(stack_b);
    if (bench)
        bench->rb_ops++;
    bench->total_ops++;
    ft_printf("rb\n", 1);
}