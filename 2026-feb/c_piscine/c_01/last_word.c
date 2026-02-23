#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	int size;
	int start;
	int end;

	if (argc == 2)
	{
		size = ft_strlen(argv[1]);
		i = size - 1;
		while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			i--;
		}

		end = i;

		while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			i--;
		}
		start = i + 1;

		while (start <= end)
		{
			ft_putchar(argv[1][start]);
			start++;
		}
	}
	ft_putchar('\n');
	return (0);
}