#include "minitalk.h"

void handler(int signum)
{
    static int i = 0;
    static char c = '\0';
    bool sig;

    sig = signum == SIGUSR1 ? 0 : 1;
    
    if(i == 7)
    {
        write(1, &c, 1);
        i = 0;
        c = '\0';
    }
    else
    {
        c |= sig << i;
        i++;
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
