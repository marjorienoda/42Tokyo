char *ft_first_char(char *nbr)
{
    while (*nbr == ' ')
    {
        nbr++;
    }
    return (nbr);
}

int ft_number_sign(char *nbr)
{
    int i;
    int sign;
    i = 0;
    sign = 1;

    while (nbr[i] != '\0')
    {
        if (nbr[i] == '-')
        {
            sign = sign * - 1;
        }
        i++;
    }
    return (sign);
}

int ft_atoi(char *nbr)
{
    long nb;
    int sign;

    nb = 0;
    sign = ft_number_sign(nbr);

    while (*nbr == '-' || *nbr == '+')
    {
        nbr++;
    }

    while (*nbr >= '0' && *nbr <= '9')
    {
        nb = nb * 10 + (*nbr - '0');
        nbr++;
    }
    return (nb * sign);
}

int get_base_size(char *base_to)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(base_to[i] != '\0')
    {
        i++;
        count++;
    }
    return (count);
}