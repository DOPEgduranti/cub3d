/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		check_to_put(char c, va_list lst);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_put_pointer(unsigned long int poi);
int		ft_putnbr_base_long(unsigned long nbr, char *base);
int		ft_putstr_nofree(char *str);

#endif
