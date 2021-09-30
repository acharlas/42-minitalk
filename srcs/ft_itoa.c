/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:23:41 by rdeban            #+#    #+#             */
/*   Updated: 2021/09/30 13:52:09 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	dec_cnt(int c)
{
	int	i;

	if (c < 0)
		i = 1;
	else
		i = 0;
	while (c)
	{
		c /= 10;
		i++;
	}
	return (i);
}

static int	isneg(int c)
{
	if (c < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int c)
{
	char				*out;
	int					i;
	const bool			neg = isneg(c);

	if (c == 0)
		return (ft_strdup("0"));
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	i = dec_cnt(c);
	if (neg)
		c *= -1;
	out = malloc(sizeof(char) * i + 1);
	if (!out)
		return (NULL);
	out[i--] = '\0';
	while (c)
	{
		out[i--] = c % 10 + 48;
		c /= 10;
	}
	if (neg)
		out[i--] = '-';
	i++;
	return (out);
}
