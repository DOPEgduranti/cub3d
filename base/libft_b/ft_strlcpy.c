/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_src;

	i = 0;
	l_src = 0;
	while (src[l_src])
		l_src++;
	if (size == 0)
		return (l_src);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l_src);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	char    c[] = "bella ciao !";
	size_t	s = 20;
	char    d0[s];
	char    d1[s];

	printf("originale : %ld\t|%s|\n", strlcpy(d0, c, s), d0);
	printf("mio : %ld\t|%s|\n", ft_strlcpy(d1, c, s), d1);
	return (0);
}*/
