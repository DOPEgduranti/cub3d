/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:07:22 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 10:47:48 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	gerr(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	return (1);
}