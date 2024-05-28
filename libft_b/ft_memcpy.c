/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*un_dest;
	unsigned char	*un_src;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	un_dest = (unsigned char *)dest;
	un_src = (unsigned char *)src;
	while (i < n)
	{
		un_dest[i] = un_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	char    c[] = "bella ciao !";
	char	d0[50];
	char	d1[50];

	memcpy(d0, c, 12);
	ft_memcpy(d1, c, 12);
	printf("originale : %s\n", d0);
	printf("mio : %s\n", d1);
	return (0);
}*/
