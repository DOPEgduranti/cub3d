/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_ndigits(long n)
{
	unsigned int	digits;

	digits = 1;
	if (n < 0)
		digits++;
	while (n / 10 != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_result(char *dst, long n, size_t *p_i)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		n /= 10;
		dst[*p_i] = c;
		*p_i += 1;
	}
	if (n % 10 != 0 || n / 10 != 0)
	{
		c = (n % 10) + '0';
		n /= 10;
		ft_result(dst, n, p_i);
		dst[*p_i] = c;
		*p_i += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*dst;
	size_t	i;
	long	l;

	i = 0;
	l = (long)n;
	dst = (char *)malloc((ft_ndigits(l) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (l < 0)
	{
		dst[i] = '-';
		i++;
		l *= -1;
	}
	ft_result (dst, l, &i);
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(400200));
	printf("%s\n", ft_itoa(-400200));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}*/
