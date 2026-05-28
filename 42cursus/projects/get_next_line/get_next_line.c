#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char *read_line(int fd, char *backup)
{
    char *line;
    char *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return(NULL);
    bytes_read = 1;
    while(!ft_strchr(backup, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read < 0)
        {
            free(buffer);
            free(backup);
            return(NULL);
        }
        buffer[bytes_read] = '\0';
        line = ft_strjoin(backup, buffer);
        free(backup);
        backup = line;
    }
    free(buffer);
    return (backup);
}

static char *extract_line(char *backup)
{
    char *line;
    int i;

    i = 0;
    while(backup[i] != '\0' && backup[i] != '\n')
        i++;
    if(backup[i] == '\n')
        i++;
    line = malloc((sizeof(char) * (i + 1)));
    if(!line)
        return(NULL);
    i = 0;
    while(backup[i] != '\0' && backup[i] != '\n')
    {
        line[i] = backup[i];
        i++;
    }
    if(backup[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return(line);
}

static char *update_backup(char *backup)
{
    int i;
    int j;
    char *new_backup;

    i = 0;
    while(backup[i] != '\0' && backup[i] != '\n')
        i++;
    if(!backup[i])
    {
        free(backup);
        return(NULL);
    }
    i++;
    new_backup = malloc(sizeof(char) * (ft_strlen(backup + i) + 1));
    if(!new_backup)
    {
        free(backup);
        return(NULL);
    }
    j = 0;
    while(backup[i] != '\0')
    {
        new_backup[j] = backup[i];
        j++;
        i++;
    }
    new_backup[j] = '\0';
    free(backup);
    return(new_backup);
} 

char *get_next_line(int fd)
{
    static char *backup;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if(!backup)
    {
        backup = ft_calloc(1, sizeof(char));
        if(!backup)
            return(NULL);
    }
    backup = read_line(fd, backup);

    if (!backup || !backup[0])
    {
        free(backup);
        backup = NULL;
        return (NULL);
    }
    line = extract_line(backup);
    backup = update_backup(backup);
    return(line);
}

// int main(void)
// {
//     int     fd;
//     char    *line;
//     int     count;

//     count = 0;
//     fd = open("example.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         return (1);
//     }
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (line == NULL)
//             break ;
//         count++;
//         printf("[%d]: %s", count, line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }

// int main(void)
// {
//     char    *line;
//     int     count;

//     count = 0;
//     while (1)
//     {
//         line = get_next_line(0);
//         if (line == NULL)
//             break ;
//         count++;
//         printf("[%d]: %s", count, line);
//         free(line);
//     }
//     return (0);
// }