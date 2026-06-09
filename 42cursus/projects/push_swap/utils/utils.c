#include "../push_swap.h"
void ft_error(char *str)
{
    ft_putendl_fd(str, 2);
    exit(1);
}

int get_start_pos(int argc, char **argv)
{
    int i;
    i = 1;
    while(i < argc)
    {
        if(argv[i][0] == '-' && argv[i][1] == '-')
            i++;
        else
            return(i);
    }
    return(i);
}

int is_bench(char **argv)
{
    if(argv[1] == '--bench')
        return(0);
    return(1);
}

t_strategy get_strategy_flag(char **argv)
{
    t_strategy strg_flag;

    if(argv[1][0] == '-' && argv[1][1] == '-' && is_bench(argv) == 1)
    {
        if(ft_strncmp(argv[1], "--simple", ft_strlen("--simple")) == 0)
            strg_flag = SIMPLE;
        else if(ft_strncmp(argv[1], "--medium", ft_strlen("--medium")) == 0)
            strg_flag = MEDIUM;
        else if(ft_strncmp(argv[1], "--complex", ft_strlen("--complex")) == 0)
            strg_flag = COMPLEX;
        else if(ft_strncmp(argv[1], "--adaptive", ft_strlen("--adaptive")) == 0)
            strg_flag = ADAPTIVE;
        else
            strg_flag = ADAPTIVE;
    }
    else if(argv[2][0] == '-' && argv[2][1] == '-' && is_bench(argv) == 0)
    {
        if(ft_strncmp(argv[1], "--simple", ft_strlen("--simple")) == 0)
            strg_flag = SIMPLE;
        else if(ft_strncmp(argv[1], "--medium", ft_strlen("--medium")) == 0)
            strg_flag = MEDIUM;
        else if(ft_strncmp(argv[1], "--complex", ft_strlen("--complex")) == 0)
            strg_flag = COMPLEX;
        else if(ft_strncmp(argv[1], "--adaptive", ft_strlen("--adaptive")) == 0)
            strg_flag = ADAPTIVE;
        else
            strg_flag = ADAPTIVE;
    }
    return(strg_flag);
}
