#include "../push_swap.h"

void sb_op(t_node **stack_b, t_bench *bench)
{
    swap_op(stack_b);
    if (bench)
        bench->sb_ops++;
    bench->total_ops++;
    ft_printf("sb\n", 1);    
}