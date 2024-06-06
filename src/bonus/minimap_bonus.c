/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:12:03 by sgarigli          #+#    #+#             */
/*   Updated: 2024/06/06 09:07:00 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>

static bool	check_player(t_vector cursor, t_data *data)
{
	return (cursor.x >= data->minimap_w / 2 - STEP_X / 2
		&& cursor.x < data->minimap_w / 2 + STEP_X / 2
		&& cursor.y >= data->minimap_h / 2 - STEP_Y / 2
		&& cursor.y < data->minimap_h / 2 + STEP_Y / 2);
}

static void	minimap_set(t_myImg *image, t_vector cursor,
	t_data *data, t_vector mini)
{
	int			r;
	t_cursor	center;

	r = fmin(data->minimap_w, data->minimap_h) / 2;
	center = (t_cursor){data->minimap_w / 2, data->minimap_h / 2};
	if ((cursor.x - center.x) * (cursor.x - center.x)
		+ (cursor.y - center.y) * (cursor.y - center.y) > r * r)
		return ;
	if (check_player(cursor, data))
		set_pixel(image, cursor.x, cursor.y, 0xFF0000);
	else if (data->map.map_mtx[(int)floor(mini.x)][(int)floor(mini.y)] == '1')
	{
		if ((int)floor((cursor.x + cursor.y)) % 2 == 1)
			set_pixel(image, cursor.x, cursor.y, 0x000000);
	}
	else if (data->map.map_mtx[(int)floor(mini.x)][(int)floor(mini.y)] == 'D')
		set_pixel(image, cursor.x, cursor.y, 0x00AAFF);
	else if (data->map.map_mtx[(int)floor(mini.x)][(int)floor(mini.y)] == 'O')
		set_pixel(image, cursor.x, cursor.y, 0x00FF00);
	else if (data->map.map_mtx[(int)floor(mini.x)][(int)floor(mini.y)] == 'B')
		set_pixel(image, cursor.x, cursor.y, 0xFFFF00);
	else
	{
		if ((int)floor((cursor.x + cursor.y)) % 2 == 1)
			set_pixel(image, cursor.x, cursor.y, 0xFFFFFF);
	}
}

void	render_minimap(t_myImg *image, t_data *data)
{
	t_vector	cursor;
	t_vector	minimap;
	t_vector	player;

	player.x = data->player.position.x - 0.5;
	player.y = data->player.position.y;
	cursor.y = 0;
	while (cursor.y < HEIGHT)
	{
		cursor.x = 0;
		while (cursor.x < WIDTH)
		{
			minimap.x = (int)floor(cursor.y / STEP_Y
					+ player.y - data->minimap_h / (2 * STEP_Y));
			minimap.y = (int)floor(cursor.x / STEP_X
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
