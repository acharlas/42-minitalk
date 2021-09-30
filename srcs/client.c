#include "minitalk.h"

int main(int argc, char **argv)
{
    char *src = argv[2];
    pid_t pid = (pid_t)atoi(argv[1]);
    char n;
    int i;

    printf("CLIENT SIDE\nPID: %d\n", getpid());
    if (argc != 3)
        printf("The client require 2 arguments. (PID, STRING)\n");
    while(*src)
    {
        n = *src;
        i = 0;
        while(i < 8)
        {
            if(n & 1 << i)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            i++;
            usleep(100);
        }

        src++;
    }
}
