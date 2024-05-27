/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:43 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/27 15:39:33 by gduranti         ###   ########.fr       */
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