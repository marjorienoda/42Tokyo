void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <stdio.h>

int	main(void)
{
	int a = 134;
	int b = 398;
	int *a_ptr;
	int *b_ptr;

	a_ptr = &a;
	b_ptr = &b;
	ft_swap(a_ptr, b_ptr);
	printf("a: %d \n", a);
	printf("b: %d", b);
}