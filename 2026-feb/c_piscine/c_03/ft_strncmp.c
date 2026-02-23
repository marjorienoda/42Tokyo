/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:15:29 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/12 11:15:39 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
	{
		return (0);
	}
	while (n > 1 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "ab";
// 	char	s2[] = "b";
// 	char	*s1_ptr;
// 	char	*s2_ptr;
// 	int		result;

// 	s1_ptr = &s1[0];
// 	s2_ptr = &s2[0];
// 	result = ft_strncmp(s1_ptr, s2_ptr, 1);
// 	printf("resultado: %d", result);
// 	return (0);
// }
