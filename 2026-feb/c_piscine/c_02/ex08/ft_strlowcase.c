char *ft_strlowcase(char *str)
{
    int counter;

    counter = 0;
    while (*str != '\0')
    {
        if (*str >= 65 && *str <= 90) 
        {
            *str = *str + 32;
        }
        str++;
        counter++;
    }
    str = str - counter;
    return str;
}
