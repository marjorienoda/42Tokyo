#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
#include <stdio.h>

int	main(void)
{
	int		i;
	char	c;

	i = 1;
	c = 'a';
	while (i <= 26)
	{
		if (i % 2 == 0)
		{
			ft_putchar(c - 32);
		}
		else
		{
			ft_putchar(c);
		}
		c++;
		i++;
	}
	ft_putchar('\n');
	return (0);
}
