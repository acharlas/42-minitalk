#include "minitalk.h"
#include <string.h>

void    encode_str(pid_t pid, char *src)
{
    int i;
    int j;
    char chr;
    int len ;

    i = 0;
    len = strlen(src);
    while(i <= len)
    {
        chr = src[i];
        j = 0;
        while(j < 8)
        {
            if(chr & 1 << j)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            j++;
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
        printf("The client require 2 arguments. (PID, STRING)\n");
    encode_str((pid_t)atoi(argv[1]), argv[2]);
}
//change atoi