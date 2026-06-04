/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:29:46 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/04 10:29:49 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_bucket(char *bucket, size_t *bucket_len, char *buffer,
		int bytes_read)
{
	char	*temp;

	temp = ft_strjoin_len(bucket, *bucket_len, buffer, bytes_read);
	if (!temp)
		return (NULL);
	*bucket_len += bytes_read;
	return (temp);
}

static char	*read_line(int fd, char *bucket)
{
	char	*buffer;
	size_t	bucket_len;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bucket_len = ft_strlen(bucket);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(buffer, bucket));
		buffer[bytes_read] = '\0';
		bucket = join_bucket(bucket, &bucket_len, buffer, bytes_read);
		if (!bucket)
			return (ft_free(buffer, NULL));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (bucket);
}

static char	*extract_line(char *bucket)
{
	char	*line;
	int		i;

	i = 0;
	while (bucket[i] != '\0' && bucket[i] != '\n')
		i++;
	if (bucket[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (bucket[i] != '\0' && bucket[i] != '\n')
	{
		line[i] = bucket[i];
		i++;
	}
	if (bucket[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_bucket(char *bucket)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (bucket[i] != '\0' && bucket[i] != '\n')
		i++;
	if (!bucket[i])
		return (ft_free(bucket, NULL));
	i++;
	new_line = malloc(sizeof(char) * (ft_strlen(bucket + i) + 1));
	if (!new_line)
		return (NULL);
	j = 0;
	while (bucket[i] != '\0')
	{
		new_line[j] = bucket[i];
		i++;
		j++;
	}
	new_line[j] = '\0';
	free(bucket);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*bucket;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bucket)
	{
		bucket = ft_calloc(1, sizeof(char));
		if (!bucket)
			return (NULL);
	}
	bucket = read_line(fd, bucket);
	if (!bucket || !bucket[0])
	{
		free(bucket);
		bucket = NULL;
		return (NULL);
	}
	line = extract_line(bucket);
	bucket = update_bucket(bucket);
	return (line);
}
