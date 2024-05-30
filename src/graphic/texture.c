/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 16:28:03 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

static int	get_index(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.direction.x < 0)
			return (WEST);
		else
			return (EAST);
	}
	if (data->ray.direction.y > 0)
		return (SOUTH);
	else
		return (NORTH);
}

void	pixels_update(t_data *data, int x)
{
	int			y;
	int			color;

	data->textures.index = get_index(data);
	data->textures.x = (int)(data->ray.wall_x * TXTR_SIZE);
	if ((data->ray.side == 0 && data->ray.direction.x < 0)
		|| (data->ray.side == 1 && data->ray.direction.y > 0))
		data->textures.x = TXTR_SIZE - data->textures.x - 1;
	data->textures.step = 1.0 * TXTR_SIZE / data->ray.line_height;
	data->textures.pos = (data->ray.draw_start - data->win_h / 2
			+ data->ray.line_height / 2) * data->textures.step;
	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->textures.y = (int)data->textures.pos & (TXTR_SIZE - 1);
		data->textures.pos += data->textures.step;
		color = data->textures.txtrs[data->textures.index][TXTR_SIZE
			* data->textures.y + data->textures.x];
		if (data->textures.index == NORTH || data->textures.index == EAST)
			color = (color >> 1) & 0x7F7F7F;
		if (!color)
			color += 1;
		data->pixels[y][x] = color;
		y++;
	}
}
