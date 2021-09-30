/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:47:52 by acharlas          #+#    #+#             */
/*   Updated: 2021/09/30 13:52:05 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	encode_str(pid_t pid, char *src)
{
	int		i;
	int		j;
	char	chr;
	int		len;

	i = 0;
	len = ft_strlen(src);
	while (i <= len)
	{
		chr = src[i];
		j = 0;
		while (j < 8)
		{
			if (chr & 1 << j)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			j++;
		}
		i++;
	}
}

int	check_pid(char *pid)
{
	while (*pid)
	{
		if (ft_isdigit(*pid) == 0)
			return (0);
		pid++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	target_pid;

	target_pid = (pid_t)ft_atoi(argv[1]);
	if (argc != 3)
	{
		write(1, "The client require 2 arguments. (PID, STRING)\n", 46);
		return (-1);
	}
	if (!check_pid(argv[1]))
	{
		write(1, "Bad pid format\n", 15);
		return (-2);
	}
	encode_str(target_pid, argv[2]);
}
