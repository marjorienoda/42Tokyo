#include <stdio.h>
char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	s1[] = "Hello";
	char	s2[10];
	int		i;

	ft_strcpy(s1, s2);
	i = 0;
	while (s2[i] != '\0')
	{
		write(1, &s2[i], 1);
		i++;
	}
	return (0);
}
