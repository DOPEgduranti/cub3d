/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	un_c;
	unsigned char	*un_s;
	size_t			i;

	un_c = (unsigned char) c;
	un_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		un_s[i] = un_c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
        char    c0[20];
	char	c1[20];

	memset(c0, 49, 10);
	ft_memset(c1, 49, 10);
        printf("originale : %s\n", c0);
	printf("mio : %s\n", c1);
        return (0);
}*/
