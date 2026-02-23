/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:13:49 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/12 11:14:32 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

#include <stdio.h>

int	main(void)
{
	char	s1[] = "Marjorie";
	char	s2[] = "m";
	char	*s1_ptr;
	char	*s2_ptr;
	int		result;

	s1_ptr = &s1[0];
	s2_ptr = &s2[0];
	result = ft_strcmp(s1_ptr, s2_ptr);
	printf("resultado: %d", result);
}
