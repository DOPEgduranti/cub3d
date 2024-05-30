/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

/*
We initialize the set up for the rays
- camera_x -> Where is the camera (-1 = left, 0 = center, 1 = right)
- direction.x/y = direction of the ray
- map.x/y = current square of the ray
- delta_dist.x/y = distance to go to the next x or y.
*/

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

/*
- We are doing the initial set up for the dda
- dda algorithm will jump one square in each loop eiter in a x or y direction
- ray->side_dist.x or y = distance from the ray start position to the
	next x or y position
- if x or y < 0 go the next x or y to the left
- if x or y > 0 go the next x or y to the right
*/

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
	bool	hit;

	hit = false;
	while (hit == false)
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
			hit = true;
		else if (data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
			!= '0')
			hit = true;
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

int	raycaster(t_data *data)
{
	int		x;

	x = 0;
	while (x < data->win_w)
	{
		reycast_init(x, data);
		dda_init(data);
		dda_exec(data);
		line_calc(data);
		pixels_update(data, x);
		x++;
	}
	return (0);
}
