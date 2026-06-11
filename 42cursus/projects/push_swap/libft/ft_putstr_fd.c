#include "../push_swap.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		counter += ft_putchar_fd(s[i], fd);
		i++;
	}
	return(counter);
}
