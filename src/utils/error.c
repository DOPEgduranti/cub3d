/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:07:22 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:01:11 by gduranti         ###   ########.fr       */
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
	ft_putstr_fd("Error\nmalloc issue", 2);
	return (1);
}

int	err_map(void)
{
	ft_putstr_fd("Error\nmap cannot be generated", 2);
	return (1);
}
