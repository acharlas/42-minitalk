#include "minitalk.h"

void handler(int signum)
{
    int sig;
    static int chr[7];
    static int i = 0;
    char n = '\0';

    sig = signum == SIGUSR1 ? 0 : 1;

   
    if(i != 7)
    {
        chr[i] = sig;
        i++;
        
    }
    if(i == 7)
    {
        i--;
        while(i)
        {
            n += chr[i] * pow(2, i);
            i--;
        }
        printf("%c", n);
    }
}

int main(void)
{
    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    printf("SERVER SIDE\nPID: %d\n", getpid());
    
    while(1);
}