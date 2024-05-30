/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16);
		ft_put_hex(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

static void	ft_put_upper_hex(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_upper_hex(num / 16);
		ft_put_upper_hex(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'A'));
	}
}

int	ft_printf_hex(unsigned long num, const char i)
{
	int	nbrchr;

	nbrchr = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (i == 'x')
		ft_put_hex(num);
	if (i == 'X')
		ft_put_upper_hex(num);
	nbrchr += ft_hex_len(num);
	return (nbrchr);
}