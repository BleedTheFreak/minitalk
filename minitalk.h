#if !defined(MINITALK_H)
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_byte
{
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
    unsigned char b8:1;
}t_byte;

int ft_atoi(char *str);
void ft_putnbr(int nbr);
void ft_putstr(char *str);

#endif // MINITALK_H
