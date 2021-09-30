/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:52:54 by acharlas          #+#    #+#             */
/*   Updated: 2021/09/30 13:52:13 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	static int		received = 0;
	static char		chr = '\0';
	static int		i = 0;
	static char		out[1000000];
	bool			sig;

	if (signum == SIGUSR1)
		sig = 0;
	else
		sig = 1;
	if (received == 7)
	{
		out[i] = chr;
		if (!chr)
		{
			write(1, out, ft_strlen(out) + 1);
			write(1, "\n", 1);
			ft_bzero(out, 8 * i);
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

int	main(void)
{
	sigset_t	set;
	char		*own_pid;

	own_pid = ft_itoa(getpid());
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	write(1, "SERVER SIDE\nPID: ", 19);
	write(1, own_pid, ft_strlen(own_pid) + 1);
	write(1, "\n", 1);
	while (1)
		;
}
