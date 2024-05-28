/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void gamestart(t_data *data)
{	
	render_images(data);
	// data->background = new_image(data, data->win_w, data->win_h);
	// background_set(data->background, data->textures.col_floor.value, data->textures.col_ceiling.value);
	// mlx_put_image_to_window(data->mlx, data->window, data->background.img, 0, 0);
}
