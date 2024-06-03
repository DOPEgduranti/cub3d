/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:12:03 by sgarigli          #+#    #+#             */
/*   Updated: 2024/06/03 11:44:17 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>

static void	minimap_set(t_myImg *image, t_cursor cursor,
	t_data *data, t_cursor minimap)
{
	if (cursor.x >= MINIMAP_W / 2 - STEP_X / 2
		&& cursor.x < MINIMAP_W / 2 + STEP_X / 2
		&& cursor.y >= MINIMAP_H / 2 - STEP_Y / 2
		&& cursor.y < MINIMAP_H / 2 + STEP_Y / 2)
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
					+ player.y - MINIMAP_H / (2 * STEP_Y));
			minimap.y = round(cursor.x / STEP_X
					+ player.x - MINIMAP_W / (2 * STEP_X));
			if (minimap.x >= 0 && minimap.x < data->map.size.y
				&& minimap.y >= 0 && minimap.y < data->map.size.x
				&& cursor.x < MINIMAP_W && cursor.y < MINIMAP_H)
				minimap_set(image, cursor, data, minimap);
			cursor.x++;
		}
		cursor.y++;
	}
}
