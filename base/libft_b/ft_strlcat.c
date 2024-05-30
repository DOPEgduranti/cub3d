/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	i = 0;
	l_dst = 0;
	l_src = 0;
	while (dst[l_dst])
		l_dst++;
	while (src[l_src])
		l_src++;
	if (size < l_dst)
		return (size + l_src);
	while (src[i] && size > 0 && l_dst < size - 1)
		dst[l_dst++] = src[i++];
	dst[l_dst] = '\0';
	while (src[i])
	{
		i++;
		l_dst++;
	}
	return (l_dst);
}
/*
#include <stdio.h>
#include <string.h>
int     main(void)
{
        char    c[] = "bella ciao !";
        char    d0[] = "mamma mia ";
		char    d1[] = "mamma mia ";

        //printf("originale : %ld\t%s\n", strlcat(d0, c, 30), d0);
        printf("mio : %ld\t%s\n", ft_strlcat(d1, c, 0), d1);
        return (0);
}*/