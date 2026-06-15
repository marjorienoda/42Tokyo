#include "../push_swap.h"

void simple_strag(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
    int min_pos;
    int size;

   while (*stack_a && stack_size(*stack_a) > 1)
    {
        min_pos = find_min_pos(*stack_a);
        size = stack_size(*stack_a);
        while (find_min_pos(*stack_a) != 0)
        {
            if (min_pos <= size / 2)
                ra_op(stack_a, bench);
            else
                rra_op(stack_a, bench);
        }
        pb_op(stack_a, stack_b, bench);
    }
    while (*stack_b)
        pa_op(stack_a, stack_b, bench);
}

