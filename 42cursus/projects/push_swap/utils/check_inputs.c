#include "../push_swap.h"

static int check_dup_nb(long nb, char **argv, int i)
{
	i++;
	while(argv[i] != NULL)
	{
		if(ft_atoil(argv[i]) == nb)
			return(1);
		i++;
	}
	return(0);
}

static int is_valid_chars(char *str)
{
	int i;

	i = 0;
	if(str[i] == '+' || str[i] == '-')
		i++;
	if(str[i] == '\0')
		return(0);
	while(str[i] != '\0')
	{
		if(!ft_isdigit(str[i]))
			return(0);
		i++; 
	}
	return(1);
}

int is_valid_input(int argc, char **argv)
{
	int i;
	long nb;

	if(argc < 2)
		return(0);
	else
	{
		i = 1;
		while(i < argc)
		{
			nb = ft_atoil(argv[i]);
			if(!is_valid_chars(argv[i]))
                ft_error("Error");
			if(check_dup_nb(nb, argv, i))
			    ft_error("Error");
			if(nb < -2147483648 || nb > 2147483647)
			    ft_error("Error");
			i++;
		}
	}
	return((int) nb);
}

struct 

--simple
flag
opt.flag..ksksksks
