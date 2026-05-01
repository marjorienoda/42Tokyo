/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:58:50 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/04/30 15:58:52 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_split allocates memory (using malloc(3)) and
 * returns an array of strings obtained by splitting s using the
 * character c as a delimiter.
 * Each string in the returned array is allocated independently.
 * The returned array must be NULL terminated.
 *
 * RETURN VALUE:
 * A array of new strings.
 * NULL If any allocation fails.
 * The returned structure will be released using:
 * 1) free() on each string in the array;
 * 2) free() the array itself.
 */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && c != s[i])
			count++;
		if (i > 0 && c != s[i] && c != s[i - 1])
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free_all(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static char	**ft_str_cpy(char **ptr, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			ptr[j] = ft_substr(s, start, i - start);
			if (!ptr[j])
				return (ft_free_all(ptr, j));
			j++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		words;

	words = count_words(s, c);
	ptr = malloc(sizeof(char *) * words + 1);
	if (!ptr)
		return (NULL);
	ft_str_cpy(ptr, s, c);
	return (ptr);
}
