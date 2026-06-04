/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:30:23 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/04 10:30:25 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	if (!s)
		return (NULL);
	while (*str != ch)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin_len(char *str1, size_t str1_len, char *str2,
		size_t str2_len)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(str1_len + str2_len + 1);
	if (!ptr)
	{
		free(str1);
		return (NULL);
	}
	i = 0;
	while (i < str1_len)
	{
		ptr[i] = str1[i];
		i++;
	}
	while (i < str1_len + str2_len)
	{
		ptr[i] = str2[i - str1_len];
		i++;
	}
	ptr[i] = '\0';
	free(str1);
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			total_size;
	size_t			i;

	if (nmemb != 0 && size > __SIZE_MAX__ / nmemb)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(sizeof(char) * total_size);
	if (!ptr)
		return (NULL);
	p = ptr;
	i = 0;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
