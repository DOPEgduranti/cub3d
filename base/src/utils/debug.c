/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	ft_printmtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx && mtx[i])
	{
		ft_putstr_fd("|", 1);
		ft_putstr_fd(mtx[i], 1);
		ft_putstr_fd("|\n", 1);
		i++;
	}
}
