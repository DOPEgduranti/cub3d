/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/06 09:55:09 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <bonus.h>

void	ft_mlx_hook(t_data *data)
{
	mlx_hook(data->window, 17, 1L << 17, ft_close_window, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_key_release, data);
	if (BONUS)
	{
		// mlx_hook(data->window, Button1, ButtonPressMask, ft_shoot, data);
		mlx_hook(data->window, MotionNotify, PointerMotionMask, ft_topo, data);
	}
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
}
