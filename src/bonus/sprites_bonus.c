/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:42:07 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/04 16:04:17 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>
#include <utils.h>
#include <time.h>

void render_weapon(t_myImg *img, t_data *data)
{
	t_cursor	cursor;
	t_cursor	txt_cursor;
	int			color;
	time_t		t;
	
	t = clock();
	cursor.y = data->win_h * 2/3;
	while (cursor.y < data->win_h)
	{
		cursor.x = data->win_w * 3/5;
		while (cursor.x < data->win_w * 4/5)
		{
			txt_cursor.x = (int)(64 * (cursor.x - data->win_w * 3/5) / (data->win_w * 1/5));
			txt_cursor.y = (int)(64 * (cursor.y - data->win_h * 2/3) / (data->win_h * 1/3));
			if ((t / (CLOCKS_PER_SEC / 2)) % 4 == 1)
				color = data->textures.txtrs[WEAPON1][txt_cursor.y * 64 + txt_cursor.x];
			else if ((t / (CLOCKS_PER_SEC / 2)) % 4 == 2)
				color = data->textures.txtrs[WEAPON2][txt_cursor.y * 64 + txt_cursor.x];
			else if ((t / (CLOCKS_PER_SEC / 2)) % 4 == 3)
				color = data->textures.txtrs[WEAPON3][txt_cursor.y * 64 + txt_cursor.x];
			else if ((t / (CLOCKS_PER_SEC / 2)) % 4 == 0)
				color = data->textures.txtrs[WEAPON4][txt_cursor.y * 64 + txt_cursor.x];
			if (color != 0x000000)
				set_pixel(img, cursor.x, cursor.y, color);
			cursor.x++;
		}
		cursor.y++;
	}	
}

void render_weapon2(t_myImg *img, t_data *data)
{
	int		x;
	int		y;
	int		tex_x;
	int		tex_y;
	int		color;

	y = data->win_h * 2/3;
	while (y < data->win_h)
	{
		x = data->win_w * 1/3;
		while (x < data->win_w * 2/3)
		{
			tex_x = (int)(64 * (x - data->win_w * 1/3) / (data->win_w * 2/3 - data->win_w * 1/3));
			tex_y = (int)(64 * (y - data->win_h * 2/3) / (data->win_h - data->win_h * 2/3));
			color = data->textures.txtrs[WEAPON1][tex_y * 64 + tex_x];
			if (color != 0x000000)
				set_pixel(img, x, y, color);
			x++;
		}
		y++;
	}	
}