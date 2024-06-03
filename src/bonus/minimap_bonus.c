/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:12:03 by sgarigli          #+#    #+#             */
/*   Updated: 2024/06/03 11:49:53 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>

static void	minimap_set(t_myImg *image, t_cursor cursor,
	t_data *data, t_cursor minimap)
{
	if (cursor.x >= data->minimap_w / 2 - STEP_X / 2
		&& cursor.x < data->minimap_w / 2 + STEP_X / 2
		&& cursor.y >= data->minimap_h / 2 - STEP_Y / 2
		&& cursor.y < data->minimap_h / 2 + STEP_Y / 2)
		set_pixel(image, cursor.x, cursor.y, 0xFF0000);
	else if (data->map.map_mtx[minimap.x][minimap.y] == '1')
		set_pixel(image, cursor.x, cursor.y, 0x000000);
	else if (data->map.map_mtx[minimap.x][minimap.y] == 'D')
		set_pixel(image, cursor.x, cursor.y, 0x00AAFF);
	else if (data->map.map_mtx[minimap.x][minimap.y] == 'O')
		set_pixel(image, cursor.x, cursor.y, 0x00FF00);
	else
		set_pixel(image, cursor.x, cursor.y, 0xFFFFFF);
}

void	render_minimap(t_myImg *image, t_data *data)
{
	t_cursor	cursor;
	t_cursor	minimap;
	t_cursor	player;

	player.x = data->player.position.x;
	player.y = data->player.position.y;
	cursor.y = 0;
	while (cursor.y < HEIGHT)
	{
		cursor.x = 0;
		while (cursor.x < WIDTH)
		{
			minimap.x = round(cursor.y / STEP_Y
					+ player.y - data->minimap_h / (2 * STEP_Y));
			minimap.y = round(cursor.x / STEP_X
					+ player.x - data->minimap_w / (2 * STEP_X));
			if (minimap.x >= 0 && minimap.x < data->map.size.y
				&& minimap.y >= 0 && minimap.y < data->map.size.x
				&& cursor.x < data->minimap_w && cursor.y < data->minimap_h)
				minimap_set(image, cursor, data, minimap);
			cursor.x++;
		}
		cursor.y++;
	}
}
