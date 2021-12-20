#include "minitalk.h"

t_byte g_byte;

int ft_byte_parse(int bit, int i)
{
    if (i == 1)
        g_byte.b1 = bit;
    else if (i == 2)
        g_byte.b2 = bit;
    else if (i == 3)
        g_byte.b3 = bit;
    else if (i == 4)
        g_byte.b4 = bit;
    else if (i == 5)
        g_byte.b5 = bit;
    else if (i == 6)
        g_byte.b6 = bit;
    else if (i == 7)
        g_byte.b7 = bit;
    else if (i == 8)
    {
        g_byte.b8 = bit;
        write(1, &*(unsigned char *)&g_byte, 1);
    }
    return (++i);
}

void ft_sighundler(int sig)
{
    static int i;

    if (i < 1 || i > 8)
        i = 1;
    if (sig == SIGUSR1)
        i = ft_byte_parse(0, i);
    else
        i = ft_byte_parse(1, i);
}

int main(int argc, char const *argv[])
{
    struct sigaction sa;

    sa.sa_handler = &ft_sighundler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_putstr("PID : ");
    ft_putnbr(getpid());
    ft_putstr("\n");
    while (1)
        pause();
    return 0;
}
