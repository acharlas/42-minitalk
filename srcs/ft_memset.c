/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:54:29 by rdeban            #+#    #+#             */
/*   Updated: 2021/09/30 13:52:10 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bst;
	unsigned char	cst;

	cst = (unsigned char)c;
	bst = (unsigned char *)b;
	while (len--)
		*bst++ = cst;
	return (b);
}
