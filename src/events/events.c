/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:43 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/16 15:55:41 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	ft_mlx_hook(t_data *data)
{
	mlx_mouse_hook(data->win, ft_mouseHook, data);
	mlx_key_hook(data->win, ft_keyHook, data);
	mlx_loop(data->mlx);
}