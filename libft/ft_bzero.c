/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:00:35 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*p;

	i = 0;
	p = s;
	while (i < n)
	{
		*p++ = '\0';
		i++;
	}
}
/*#include <stdio.h>
int main ()
{
	char s[] = "qweuollao";
	ft_bzero(s, 2);
	printf("%s \n",&s[4]);
}*/
