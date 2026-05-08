/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:43:03 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/08 14:43:05 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * DESCRIPTION:
 * The function ft_strmapi applies the function f to each character
 * of the string s.
 * A new string is created (using malloc(3)) to store the result
 * from the successive applications of f.
 *
 * RETURN VALUE:
 * The pointer to the new string.
 * NUll if fails.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	str_len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str_len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (str_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
