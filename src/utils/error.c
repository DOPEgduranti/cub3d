/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:00:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	err_gen(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int	err_malloc(void)
{
	ft_putstr_fd("Error\nmalloc issue\n", 2);
	return (1);
}

int	err_map(void)
{
	ft_putstr_fd("Error\nmap cannot be generated\n", 2);
	return (1);
}
