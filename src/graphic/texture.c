/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:30:33 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/24 11:25:30 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void	pixels_init(t_data *data)
{
	int	i;

	if (data->pixels)
		ft_freemtx((void **)data->pixels);
	data->pixels = ft_calloc(data->wih_h + 1, sizeof(int *));
	if (!data->pixels)
		return (exit(1));
	i = 0;
	while (i < data->wih_h)
	{
		data->pixels[i] = ft_calloc(data->win_w + 1, sizeof(int));
		if (!data->pixels[i])
			return (ft_freemtx((void **)data->pixels), exit(1));
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
	data->textures.pos = (data->ray.draw_start - data->wih_h / 2 + data->ray.line_height / 2) * data->textures.step;
	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->textures.y = (int)data->textures.pos & (data->textures.size - 1);
		data->textures.pos += data->textures.step;
		color = data->textures.txtrs[data->textures.index][data->textures.size * data->textures.y + data->textures.x];
		if (data->textures.index == NORTH || data->textures.index == EAST) // for shadows
			color = (color >> 1) & 8355711;
		if (!color)
			color += 1;
		data->pixels[y][x] = color;
		y++;
	}
}
