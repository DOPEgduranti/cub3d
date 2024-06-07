/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:42:07 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/07 11:43:44 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>
#include <utils.h>
#include <time.h>
#include <graphic.h>

static int	shoot_animation(t_data *data, t_cursor txt_cursor, time_t t)
{
	int			color;

	color = 0x000000;
	if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 0)
		color = data->textures.txtrs[SHOOT1][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 1)
		color = data->textures.txtrs[SHOOT2][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 2)
		color = data->textures.txtrs[SHOOT3][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 3)
		color = data->textures.txtrs[SHOOT4][txt_cursor.y * 64 + txt_cursor.x];
	return (color);
}

static int	set_color(t_data *data, t_cursor txt_cursor)
{
	int			color;
	time_t		t;

	t = clock();
	color = 0x000000;
	if (data->player.is_shooting)
		return (shoot_animation(data, txt_cursor, t));
	if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 0)
		color = data->textures.txtrs[WEAPON1][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 1)
		color = data->textures.txtrs[WEAPON2][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 2)
		color = data->textures.txtrs[WEAPON3][txt_cursor.y * 64 + txt_cursor.x];
	else if ((t / (CLOCKS_PER_SEC / 4)) % 4 == 3)
		color = data->textures.txtrs[WEAPON4][txt_cursor.y * 64 + txt_cursor.x];
	return (color);
}

static t_vector	vect_init(t_data *data)
{
	t_vector	vect;

	vect.x = 0.66;
	vect.y = 1.00;
	if (data->player.is_shooting)
	{
		vect.x = 0.40;
		vect.y = 0.85;
	}
	return (vect);
}

void	render_weapon(t_myImg *img, t_data *data)
{
	t_cursor	cursor;
	t_cursor	txt_cursor;
	int			color;
	t_vector	vect;

	vect = vect_init(data);
	cursor.y = data->win_h * vect.x;
	while (cursor.y < data->win_h * vect.y)
	{
		cursor.x = data->win_w * 0.40;
		while (cursor.x < data->win_w * 0.60)
		{
			txt_cursor.x = (int)(64
					* (cursor.x - data->win_w * 0.40) / (data->win_w * 0.20));
			txt_cursor.y = (int)(64
					* (cursor.y - data->win_h * vect.x)
					/ (data->win_h * (vect.y - vect.x)));
			color = set_color(data, txt_cursor);
			if (color != 0x000000)
				set_pixel(img, cursor.x, cursor.y, color);
			cursor.x++;
		}
		cursor.y++;
	}
}
