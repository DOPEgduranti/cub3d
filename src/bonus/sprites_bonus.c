/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:42:07 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/04 16:14:10 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>
#include <utils.h>
#include <time.h>

static int	set_color(t_data *data, t_cursor txt_cursor)
{
	int			color;
	time_t		t;

	t = clock();
	color = 0x000000;
	if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 1)
		color = data->textures.txtrs[WEAPON1][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 2)
		color = data->textures.txtrs[WEAPON2][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 3)
		color = data->textures.txtrs[WEAPON3][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 0)
		color = data->textures.txtrs[WEAPON4][txt_cursor.y * 64 + txt_cursor.x];
	return (color);
}

void	render_weapon(t_myImg *img, t_data *data)
{
	t_cursor	cursor;
	t_cursor	txt_cursor;
	int			color;
	

	cursor.y = data->win_h * 2 / 3;
	while (cursor.y < data->win_h)
	{
		cursor.x = data->win_w * 3 / 5;
		while (cursor.x < data->win_w * 4 / 5)
		{
			txt_cursor.x = (int)(64
					* (cursor.x - data->win_w * 3 / 5) / (data->win_w * 1 / 5));
			txt_cursor.y = (int)(64
					* (cursor.y - data->win_h * 2 / 3) / (data->win_h * 1 / 3));
			color = set_color(data, txt_cursor);
			if (color != 0x000000)
				set_pixel(img, cursor.x, cursor.y, color);
			cursor.x++;
		}
		cursor.y++;
	}
}
