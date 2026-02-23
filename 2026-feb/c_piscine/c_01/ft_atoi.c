int	ft_number_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	long	nb;
	int		sign;
	int		i;

	i = 0;
	nb = 0;
	sign = ft_number_sign(str);
	while (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

#include <stdio.h>

int	main(void)
{
	char strg[] = "-12345";
	char *str_ptr;

	str_ptr = strg;

	printf("%d", ft_atoi(str_ptr));
	return (0);
}