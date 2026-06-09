#include "../push_swap.h"
void ft_error(char *str)
{
    ft_putendl_fd(str, 2);
    exit(1);
}

int get_start_pos(int argc, char **argv)
{
    int i;
    int j;
    i = 1;
    while(i < argc)
    {
        if(argv[i][0] == '-' && argv[i][1] == '-')
            i++;
        j = 2;
        while(!ft_isdigit(argv[i][j]))
        else
            return(i);
    }
    return(i);
}

t_strategy get_strategy_flag(char **argv)
{
    
}