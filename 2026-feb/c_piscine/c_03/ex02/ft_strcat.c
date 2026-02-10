char *ft_strcat(char *dest, char *src)
{
    char *dest_ptr;

    dest_ptr = dest;

    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
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

// 	char *result = ft_strcat(string_dest_ptr, string_src_ptr);

// 	while (*result != '\0')
// 	{
// 		write(1, result, 1);
// 		result++;
// 	}
// 	return (0);
// }