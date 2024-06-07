/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:42:07 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/07 10:14:06 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>
#include <utils.h>

static void	reycast_init(int x, t_data *data)
{
	data->ray.map.x = (int)data->player.position.x;
	data->ray.map.y = (int)data->player.position.y;
	data->ray.camera_x = 2 * x / (double)data->win_w - 1;
	data->ray.direction.x = data->player.direction.x
		+ data->player.plane.x * data->ray.camera_x;
	data->ray.direction.y = data->player.direction.y
		+ data->player.plane.y * data->ray.camera_x;
	data->ray.delta_dist.x = fabs(1 / data->ray.direction.x);
	data->ray.delta_dist.y = fabs(1 / data->ray.direction.y);
}

static void	dda_init(t_data *data)
{
	if (data->ray.direction.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.side_dist.y = (data->player.position.y - data->ray.map.y)
			* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.side_dist.y = (data->ray.map.y + 1.0
				- data->player.position.y) * data->ray.delta_dist.y;
	}
	if (data->ray.direction.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.side_dist.x = (data->player.position.x - data->ray.map.x)
			* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.side_dist.x = (data->ray.map.x + 1.0
				- data->player.position.x) * data->ray.delta_dist.x;
	}
}

/*
- We implement the DDA algorithm -> the loop will increment 1 square 
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/

static void	dda_exec(t_data *data)
{
	data->ray.hit = false;
	data->ray.foe = false;
	while (data->ray.hit == false)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side = 0;
			data->ray.map.x += data->ray.step.x;
			data->ray.side_dist.x += data->ray.delta_dist.x;
		}
		else
		{
			data->ray.side = 1;
			data->ray.map.y += data->ray.step.y;
			data->ray.side_dist.y += data->ray.delta_dist.y;
		}
		if (data->ray.map.y < 0.25 || data->ray.map.x < 0.25
			|| data->ray.map.y > data->map.size.y - 0.25
			|| data->ray.map.x > data->map.size.x - 1.25)
			data->ray.hit = true;
		else if (data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
			== '1' || data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
			== 'D')
			data->ray.hit = true;
		else if (data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
			== 'F')
		{
			data->ray.hit = true;
			data->ray.foe = true;
		}
	}
}

static void	line_calc(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_dist = (data->ray.side_dist.x - data->ray.delta_dist.x);
	else
		data->ray.wall_dist = (data->ray.side_dist.y - data->ray.delta_dist.y);
	data->ray.line_height = (int)(data->win_h / data->ray.wall_dist);
	data->ray.draw_start = -(data->ray.line_height) / 2 + data->win_h / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + data->win_h / 2;
	if (data->ray.draw_end >= data->win_h)
		data->ray.draw_end = data->win_h - 1;
	if (data->ray.side == 0)
		data->ray.wall_x = data->player.position.y + data->ray.wall_dist
			* data->ray.direction.y;
	else
		data->ray.wall_x = data->player.position.x + data->ray.wall_dist
			* data->ray.direction.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

static void	image_update(t_myImg *img, t_data *data, int *x)
{
	int			y;
	int			color;
	int			tmp;

	data->textures.x = (int)(data->ray.wall_x * TXTR_SIZE);
	if ((data->ray.side == 0 && data->ray.direction.x < 0)
		|| (data->ray.side == 1 && data->ray.direction.y > 0))
		data->textures.x = TXTR_SIZE - data->textures.x - 1;
	data->textures.step = 1.0 * TXTR_SIZE / data->ray.line_height;
	data->textures.pos = (data->ray.draw_start - data->win_h / 2
			+ data->ray.line_height / 2) * data->textures.step;
	tmp = 0;
	while (tmp < TXTR_SIZE)
	{
		y = data->ray.draw_start;
		while (y < data->ray.draw_end)
		{
			data->textures.y = (int)data->textures.pos & (TXTR_SIZE - 1);
			data->textures.pos += data->textures.step;
			color = data->textures.txtrs[FOE][TXTR_SIZE
				* data->textures.y + data->textures.x + tmp];
			if (color != 0x000000)
				set_pixel(img, *x, y, color);
			y++;
		}
		(*x)++;
	tmp++;
	}
}

void	render_sprite(t_myImg *img, t_data *data)
{
	int	x;

	x = 0;
	if (!data->ray.foe)
		return ;
	data->ray.map = data->ray.foe_pos;
	while (x < data->win_w)
	{
		reycast_init(x, data);
		dda_init(data);
		dda_exec(data);
		if (!data->ray.foe)
		{
			x++;
			continue ;
		}
		line_calc(data);
		image_update(img, data, &x);
		return ;
	}
}
