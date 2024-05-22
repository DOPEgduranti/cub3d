/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:43 by sgarigli          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/16 15:55:41 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	ft_mlx_hook(t_data *data)
{
	mlx_mouse_hook(data->win, ft_mouseHook, data);
	mlx_key_hook(data->win, ft_keyHook, data);
=======
/*   Updated: 2024/05/20 12:21:49 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

void	ft_mlx_hook(t_data *data)
{
	mlx_mouse_hook(data->window, ft_mouseHook, data);
	mlx_key_hook(data->window, ft_keyHook, data);
	mlx_hook(data->window, 17, 1L << 17, ft_close_window, data);
>>>>>>> 361e6247634075974bcfa3f4dfeb389722b98dc1
	mlx_loop(data->mlx);
}