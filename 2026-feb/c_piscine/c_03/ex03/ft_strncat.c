char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    char *dest_ptr;
    unsigned int counter;

    dest_ptr = dest;

    while (*dest != '\0')
    {
        dest++;
    }
    counter = 0;
    while (*src != '\0' && counter < nb)
    {
        *dest = *src;
        src++;
        dest++;
        counter++;
    }
    dest = '\0';

    return dest_ptr;
}

// #include <unistd.h>
// int main(void)
// {
//     char string_src[] = "World";
//     char string_dest[100] = "Hello";

// 	char *string_src_ptr = &string_src[0];
//     char *string_dest_ptr = &string_dest[0];

// 	char *result = ft_strncat(string_dest_ptr, string_src_ptr, 3);

// 	while (*result != '\0')
// 	{
// 		write(1, result, 1);
// 		result++;
// 	}
// 	return (0);
// }