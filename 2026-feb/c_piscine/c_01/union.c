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
	int k;
	int count;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			j = 0;
			while (argv[2][i] != '\0')
			{
				count = 0;
				k = 0;
				if (argv[1][k] == argv[1][i])
				{
					count = 1;
				}
				else if (argv[2][k] == argv[2][j])
				{
					count = 1;
				}
				k++;

				if (count == 0)
				{
					if (argv[1][i] == argv[2][j])
					{
						ft_putchar(argv[1][i]);
					}
					else if (argv[1][i] == '\0')
					{
						ft_putchar(argv[2][j]);
					}
					i++;
					j++;
				}
			}
		}
	}
	ft_putchar('\n');
	return (0);
}