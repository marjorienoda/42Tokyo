#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


void    print_newline_helper(char *buffer)
{

    while (*buffer &&  *buffer != '\0')
    {
        if (*buffer == '\n') 
        {
            *buffer= '\\';
        }
        printf("%c \n",*buffer);
        buffer++;
    }
}

char *get_next_line(int fd)
{
    static char *backup;
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    printf("[ANTES DO CALLOC] Meu backup estático vale: %s\n", backup);
    backup = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if(!backup)
        return(NULL);
    bytes_read = read(fd, line, BUFFER_SIZE);
    printf("[DEPOIS DO READ] O read colocou isso no backup: '%s' (bytes lidos: %d)\n", backup, bytes_read);
    if(bytes_read <= 0)
    {
        free(backup);
        return(NULL);
    }
    return(backup);
}

int main(void)
{
    int    fd;
    char  *next_line;
    int  count;

    count = 0;
    fd = open("example.txt", O_RDONLY);
    while (1)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break ;
        count++;
        printf("[%d]:%s\n", count, next_line);
        free(next_line);
        next_line = NULL;
    }

    close(fd);
    return (0);
}