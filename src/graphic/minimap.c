/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:12:03 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/31 15:32:23 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void render_minimap(t_data *data)
{
	t_myImg	image;
	int		x;
	int		y;
	int 	i;
	int 	j;
	int 	step_x;
	int 	step_y;
	int 	player_x;
	int 	player_y;
	
	image.img = NULL;
	image = myimg_empty(data, MINIMAP_W, MINIMAP_H);
	step_x = MINIMAP_W / data->map.size.x;
	step_y = MINIMAP_H / data->map.size.y;
	player_x = data->player.position.x * step_x - step_x / 2;
	player_y = data->player.position.y * step_y - step_y / 2;
	y = 0;
	while (y < MINIMAP_H)
	{
		x = 0;
		while (x < MINIMAP_W)
		{
			i = round(y / step_y);
			j = round(x / step_x);
			if (x >= player_x && x < player_x + step_x && y >= player_y && y < player_y + step_y)
				set_pixel(&image, x, y, 0xFF0000);
			else if (data->map.map_mtx[i][j] == '1')
				set_pixel(&image, x, y, 0x000000);
			else if (data->map.map_mtx[i][j] == 'D')
				set_pixel(&image, x, y, 0x00FF00);
			else
				set_pixel(&image, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, image.img, WIDTH - MINIMAP_W, HEIGHT - MINIMAP_H);
	mlx_destroy_image(data->mlx, image.img);
}
