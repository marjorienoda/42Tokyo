#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	int j;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = argc - 1;
	j = 0;
	while (argv[i][j])
	{
		ft_putchar(argv[i][j]);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}