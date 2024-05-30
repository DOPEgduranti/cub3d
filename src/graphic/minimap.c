/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:12:03 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/30 16:26:35 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void render_minimap(t_data *data)
{
	t_myImg	image;
	int		x;
	int		y;

	image.img = NULL;
	image = myimg_empty(data, MINIMAP_W, MINIMAP_H);
	y = 1;
	while (y < MINIMAP_H)
	{
		x = 1;
		while (x < MINIMAP_W)
		{
			if (data->map.map_mtx[y % (int)data->map.size.y][x % (int)data->map.size.x] == '1')
				set_pixel(&image, x, y, 0x000000);
			else
				set_pixel(&image, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, image.img, WIDTH - MINIMAP_W, HEIGHT - MINIMAP_H);
	mlx_destroy_image(data->mlx, image.img);
}