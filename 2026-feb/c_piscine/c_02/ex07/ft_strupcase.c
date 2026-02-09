char *ft_strupcase(char *str)
{
    int counter;

    counter = 0;
    while (*str != '\0')
    {
        if (*str >= 97 && *str <= 122) 
        {
            *str = *str - 32;
        }
        str++;
        counter++;
    }
    str = str - counter;
    return str;
}
