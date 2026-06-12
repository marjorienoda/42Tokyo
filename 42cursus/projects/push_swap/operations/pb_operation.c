#include "../push_swap.h"

void pb_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
    t_node *node_to_move;

    if(!*stack_a)
        return;
    node_to_move = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    if(*stack_a)
        (*stack_a)->prev = NULL;
    if (!*stack_b)
    {
        node_to_move->next = NULL;
        node_to_move->prev = NULL;
        *stack_b = node_to_move;
    }
    else
    {
        node_to_move->next = *stack_b;
        node_to_move->prev = NULL;
        (*stack_b)->prev = node_to_move;
        *stack_b = node_to_move;
    }
    if (bench)
        bench->pb_ops++;
    bench->total_ops++;
    ft_printf("pb\n", 1);
}