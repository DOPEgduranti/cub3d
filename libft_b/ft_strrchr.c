/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
        const char str[] = "mamma mia bella ciao !";
        const char ch = '\0';

        printf("String after |%c| is - |%s|\n", ch, strrchr(str, ch));
        printf("String after |%c| is - |%s|\n", ch, ft_strrchr(str, ch));
        return(0);
}*/
