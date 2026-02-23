#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_repeat_char(char *str)
{
	int	i;
	int	repeat;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			repeat = str[i] - 'a' + 1;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			repeat = str[i] - 'A' + 1;
		}
		while (repeat > 0)
		{
			ft_putchar(str[i]);
			repeat--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_repeat_char(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
