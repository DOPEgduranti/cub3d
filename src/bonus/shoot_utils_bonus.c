/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:29:17 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/06 11:33:15 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>
#include <graphic.h>
#include <time.h>

void	render_shooting(t_myImg *img, t_data *data)
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
			color = data->textures.txtrs[SHOOT][txt_cursor.y * 64 + txt_cursor.x];
			if (color != 0x000000)
				set_pixel(img, cursor.x, cursor.y, color);
			cursor.x++;
		}
		cursor.y++;
	}

}