#include "../push_swap.h"

void ft_free_stack(t_node *stack)
{
    t_node *current;
    t_node *next;

    current = stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

t_node *stack_last(t_node *node)
{
    t_node *current;
    current = node;

    if(current == NULL)
        return(NULL);
    while(current->next != NULL)
        current = current->next;
    return(current);
}

void stack_add_bottom(t_node **stack, t_node *new)
{
    t_node *last;

    if(!new)
        return;
    if(*stack == NULL)
    {
        *stack = new;
        return;
    }
    last = stack_last(*stack);
    last->next = new;
    new->prev = last;
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
