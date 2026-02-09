char *ft_strcpy(char *dest, char *src)
{
    int characters;

    characters = 0;

    while (*src != '\0')
    {
        *dest = *src;
        characters++;
        src++;
        dest++;
    }
    *dest = '\0';
    dest = dest - characters;
    return (dest);
}
