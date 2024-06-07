/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:43:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/07 09:29:11 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>
#include <graphic.h>
#include <time.h>

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

static void	ft_hit_obstacle(t_data *data)
{
	if (data->ray.map.y < 0.25 || data->ray.map.x < 0.25
		|| data->ray.map.y > data->map.size.y - 0.25
		|| data->ray.map.x > data->map.size.x - 1.25)
		data->ray.hit = true;
	else if (data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
		== '1' || data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
		== 'D')
		data->ray.hit = true;
}

static void	dda_exec(t_data *data)
{
	data->ray.hit = false;
	while (data->ray.hit == false)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.map.x += data->ray.step.x;
			data->ray.side_dist.x += data->ray.delta_dist.x;
		}
		else
		{
			data->ray.map.y += data->ray.step.y;
			data->ray.side_dist.y += data->ray.delta_dist.y;
		}
		ft_hit_obstacle(data);
		if (data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
			== 'B')
		{
			data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x] = 'X';
			data->ray.hit = true;
		}
	}
}

int	ft_shoot(t_data *data)
{
	int		x;

	data->player.is_shooting = true;
	x = data->win_w / 2;
	data->ray.map.x = (int)data->player.position.x;
	data->ray.map.y = (int)data->player.position.y;
	data->ray.camera_x = 2 * x / (double)data->win_w - 1;
	data->ray.direction.x = data->player.direction.x
		+ data->player.plane.x * data->ray.camera_x;
	data->ray.direction.y = data->player.direction.y
		+ data->player.plane.y * data->ray.camera_x;
	data->ray.delta_dist.x = fabs(1 / data->ray.direction.x);
	data->ray.delta_dist.y = fabs(1 / data->ray.direction.y);
	dda_init(data);
	dda_exec(data);
	return (0);
}
