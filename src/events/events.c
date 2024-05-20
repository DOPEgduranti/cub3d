/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:43 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/20 10:49:35 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

void	ft_mlx_hook(t_data *data)
{
	mlx_mouse_hook(data->window, ft_mouseHook, data);
	mlx_key_hook(data->window, ft_keyHook, data);
	mlx_hook(data->window, 17, 1L << 17, ft_close_window, data);
	mlx_loop(data->mlx);
}