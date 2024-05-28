/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = (char *)s;
	i = 0;
	while (res[i])
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	if (res[i] == (unsigned char)c)
		return (&res[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	const char str[] = "mamma mia bella ciao !";
	const char ch = '\0';
	
	printf("String after |%c| is - |%s|\n", ch, strchr(str, ch));
	printf("String after |%c| is - |%s|\n", ch, ft_strchr(str, ch));
	printf("%p\n", strchr("teste", 'e'));
	printf("%p\n", ft_strchr("teste", 'e'));
	return(0);
}*/
