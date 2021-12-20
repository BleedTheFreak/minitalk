#include "minitalk.h"

void ft_send_sig(int bit, pid_t pid)
{
    if (bit == 0)
    {
        if (kill(pid, SIGUSR1) == -1)
        {
            ft_putstr("Problem sending the signal!\n");
			exit(1);
        }
        usleep(150);
    }
    else
    {
        if (kill(pid, SIGUSR2) == -1)
        {
            ft_putstr("Problem sending the signal!\n");
			exit(1);
        }
        usleep(150);
    }
}

void ft_parse_to_bits(int c, pid_t pid)
{
    t_byte byte;

    *(unsigned char*)&byte = (unsigned char) c;
    ft_send_sig(byte.b1, pid);
    ft_send_sig(byte.b2, pid);
    ft_send_sig(byte.b3, pid);
    ft_send_sig(byte.b4, pid);
    ft_send_sig(byte.b5, pid);
    ft_send_sig(byte.b6, pid);
    ft_send_sig(byte.b7, pid);
    ft_send_sig(byte.b8, pid);
}

int main(int argc, char const *argv[])
{ 
    pid_t pid;
    int i;
    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi((char *)argv[1]);
        ft_putnbr(pid);
        if (pid == 0 || pid < 0)
        {
            ft_putstr("Invalid PID \n");
            return (0);
        }
        while (argv[2][i])
        {
            ft_parse_to_bits(argv[2][i], pid);
            i++;
        }
        
    }
    else
        ft_putstr("Example : ./client [PID] [Message]\n");
    return 0;
}
