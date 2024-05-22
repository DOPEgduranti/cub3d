/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:25 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/22 12:20:28 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void gamestart(t_data *data)
{	
	render_images(data);
	// data->background = new_image(data, WIDTH, HEIGHT);
	// background_set(data->background, data->textures.col_floor.value, data->textures.col_ceiling.value);
	// mlx_put_image_to_window(data->mlx, data->window, data->background.img, 0, 0);
}