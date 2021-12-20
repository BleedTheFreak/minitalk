#include "minitalk.h"

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void ft_putnbr(int nbr)
{
    char *base;

    base = "0123456789";
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr *= -1;
    }
    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
        write(1, &base[nbr], 1);
}

int ft_atoi(char *str)
{
    int number;
    int sign;
    int i;

    i = 0;
    sign = 1;
    number = 0;

    while (str[i] <= 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return (number * sign);
}