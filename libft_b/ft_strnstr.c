/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j]
			&& i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	if (little[j])
		return (NULL);
	return ((char *)big);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
        const char s1[] = "ciao amico mio";
        const char s2[] = "m";

        printf("corretto : %s\n", strstr(s1, s2));
        printf("mio : %s\n", ft_strnstr(s1, s2, 5));
        return(0);
}*/
