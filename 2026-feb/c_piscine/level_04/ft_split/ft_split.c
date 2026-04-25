/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <stdlib.h>
#include <stdio.h>

int ft_count_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 1;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            count = count + 1;
        }
        i++;
    }
    return (count);
}

// char    **ft_split(char *str)
// {

// }



int main (void)
{
    char str[] = "casa banana";
    printf("%d", ft_count_words(str));
    return (0);
}