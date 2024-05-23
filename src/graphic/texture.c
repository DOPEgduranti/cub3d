/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:30:33 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/23 11:23:33 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void	init_pixels(t_data *data)
{
	int	i;

	// if (data->pixels)
	// 	ft_freemtx(&data->pixels);
	data->pixels = ft_calloc(data->win_height + 1, sizeof * data->pixels);
	if (!data->pixels)
		return (exit(1));
	i = 0;
	while (i < data->win_height)
	{
		data->pixels[i] = ft_calloc(data->win_width + 1, sizeof * data->pixels);
		if (!data->pixels[i])
			return (exit(1));
		i++;
	}
}

static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->direction.x < 0)
			data->textures.index = WEST;
		else
			data->textures.index = EAST;
	}
	else
	{
		if (ray->direction.y > 0)
			data->textures.index = SOUTH;
		else
			data->textures.index = NORTH;
	}
}

void	update_pixels(t_data *data, t_textures *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->direction.x < 0) || (ray->side == 1 && ray->direction.y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures.txtrs[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->pixels[y][x] = color;
		y++;
	}
}
