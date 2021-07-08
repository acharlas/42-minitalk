#include "minitalk.h"

int main(int argc, char **argv)
{
    char *src = argv[2];
    pid_t pid = (pid_t)atoi(argv[1]); 

    printf("CLIENT SIDE\nPID: %d\n", getpid());
    if (argc != 3)
        printf("The client require 2 arguments. (PID, STRING)\n");
    while(*src)
    {
        int n = *src;
        while(n > 0)
        {
            if(n % 2 == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            n = n / 2;
            usleep(40);
        }
        src++;
    }
}