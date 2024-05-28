/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(va_list args, const char i)
{
	int				nbrchr;

	nbrchr = 0;
	if (i == 'c')
		nbrchr += ft_putchar(va_arg(args, int));
	else if (i == '%')
		nbrchr += ft_putchar('%');
	else if (i == 's')
		nbrchr += ft_putstr(va_arg(args, const char *));
	else if (i == 'd')
		nbrchr += ft_freeputstr((const char *)ft_itoa(va_arg(args, int)));
	else if (i == 'i')
		nbrchr += ft_freeputstr((const char *)ft_itoa(va_arg(args, int)));
	else if (i == 'u')
		nbrchr += ft_freeputstr((const char *)
				ft_uitoa(va_arg(args, unsigned int)));
	else if (i == 'p')
		nbrchr += ft_printf_pointer(va_arg(args, unsigned long int));
	else if (i == 'x' || i == 'X')
		nbrchr += ft_printf_hex(va_arg(args, unsigned int), i);
	return (nbrchr);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_print_args(args, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
