char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int counter;

    counter = 0;

    while (counter < n)
    {
        *dest = *src;
        counter++;
        src++;
        dest++;
    }
    *dest = '\0';
    dest = dest - counter;
    return (dest);
}
