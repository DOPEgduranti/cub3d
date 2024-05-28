/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void	pixels_init(t_data *data)
{
	int	i;

	if (data->pixels)
		ft_freemtx((void **)data->pixels);
	data->pixels = ft_calloc(data->win_h + 1, sizeof(int *));
	if (!data->pixels)
		return (err_malloc(), free_data(data), exit(1));
	i = 0;
	while (i < data->win_h)
	{
		data->pixels[i] = ft_calloc(data->win_w + 1, sizeof(int));
		if (!data->pixels[i])
			return (err_malloc(), free_data(data), exit(1));
		i++;
	}
}

static void	get_index(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.direction.x < 0)
			data->textures.index = WEST;
		else
			data->textures.index = EAST;
	}
	else
	{
		if (data->ray.direction.y > 0)
			data->textures.index = SOUTH;
		else
			data->textures.index = NORTH;
	}
}

void	pixels_update(t_data *data, int x)
{
	int			y;
	int			color;

	get_index(data);
	data->textures.x = (int)(data->ray.wall_x * data->textures.size);
	if ((data->ray.side == 0 && data->ray.direction.x < 0) || (data->ray.side == 1 && data->ray.direction.y > 0))
		data->textures.x = data->textures.size - data->textures.x - 1;
	data->textures.step = 1.0 * data->textures.size / data->ray.line_height;
	data->textures.pos = (data->ray.draw_start - data->win_h / 2 + data->ray.line_height / 2) * data->textures.step;
	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->textures.y = (int)data->textures.pos & (data->textures.size - 1);
		data->textures.pos += data->textures.step;
		color = data->textures.txtrs[data->textures.index][data->textures.size * data->textures.y + data->textures.x];
		if (data->textures.index == NORTH || data->textures.index == EAST) // for shadows
			color = (color >> 1) & 0x7F7F7F;
		if (!color)
			color += 1;
		data->pixels[y][x] = color;
		y++;
	}
}
