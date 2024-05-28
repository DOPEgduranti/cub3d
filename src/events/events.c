/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

void	ft_mlx_hook(t_data *data)
{
	mlx_mouse_hook(data->window, ft_mouseHook, data);
	mlx_hook(data->window, 17, 1L << 17, ft_close_window, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keyHook, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyReleaseHook, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
}
