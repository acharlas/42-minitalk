/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:52:54 by acharlas          #+#    #+#             */
/*   Updated: 2021/09/30 11:56:00 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <strings.h>

void handler(int signum)
{
	static int received = 0;
    static char chr = '\0';
	static int i = 0;
	static char out[1000000];
    bool sig;

    sig = signum == SIGUSR1 ? 0 : 1;
    
    if(received == 7)
    {
        out[i] = chr;
		if (!chr)
		{
			printf("%s\n", out);
			bzero(out, 8 * i);
			i = 0;
			chr = '\0';
			received = 0;
			return ;
		}
		chr = '\0';
		received = 0;
		i++;
    }
    else
    {
        chr |= (sig << received);
        received++;
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
