#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	char str[] = "Hello!";
	char *str_ptr;

	str_ptr = str;
	ft_putstr(str_ptr);
	return (0);
}