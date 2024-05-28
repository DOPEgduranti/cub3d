/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*un_s;
	size_t			i;

	un_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		un_s[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	char    c0[] = "bella ciao !";
	char    c1[] = "bella ciao !";

	bzero(c0, 6);
	ft_bzero(c1, 6);
	printf("originale : %c\n", c0[7]);
	printf("mio : %c\n", c1[7]);
	return (0);
}*/
