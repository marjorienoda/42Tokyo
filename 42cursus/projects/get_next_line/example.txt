#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

static void	test_file(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	printf("\n--- testing: %s ---\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("error opening file\n");
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]: %s \n", count, line);
		free(line);
	}
	printf("total lines: %d\n", count);
	close(fd);
}

int	main(void)
{
	char	*line;

	printf("\n=== test fd = 0 (stdin) ===\n");
	printf("type some lines (ctrl+d to stop):\n");
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		printf("read: %s", line);
		free(line);
	}

	printf("\n=== test normal file ===\n");
	test_file("example.txt");

	printf("\n=== test non-existent file ===\n");
	test_file("does_not_exist.txt");

	printf("\n=== test negative fd ===\n");
	line = get_next_line(-1);
	if (line == NULL)
		printf("negative fd: returned NULL correctly\n");
	else
	{
		printf("negative fd: ERROR, returned something\n");
		free(line);
	}

	return (0);
}