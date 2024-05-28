/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1024);
	if (c >= 'a' && c <= 'z')
		return (1024);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int     main(void)
{
        char    c = 'Z';

        printf("originale : %d\n", isalpha(c));
        printf("mio : %d\n", ft_isalpha(c));
        return (0);
}*/
