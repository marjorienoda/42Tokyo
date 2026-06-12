#include "../push_swap.h"

void sa_op(t_node **stack_a, t_bench *bench)
{
    swap_op(stack_a);
    if (bench)
        bench->sa_ops++;
    bench->total_ops++;
    ft_printf("sa\n", 1);    
}