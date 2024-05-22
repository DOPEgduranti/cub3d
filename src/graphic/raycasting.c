/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:40:40 by alexa             #+#    #+#             */
/*   Updated: 2024/05/22 15:49:31 by gduranti         ###   ########.fr       */
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

static void	init_raycasting_info(int x, t_ray *ray, t_player *player, t_data *data)
{
	ray->camera_x = 2 * x / (double)data->win_width - 1;
	ray->direction.x = player->direction.x + player->plane.x * ray->camera_x;
	ray->direction.y = player->direction.y + player->plane.y * ray->camera_x;
	ray->map.x = (int)player->position.x;
	ray->map.y = (int)player->position.y;
	ray->delta_dist.x = fabs(1 / ray->direction.x);
	ray->delta_dist.y = fabs(1 / ray->direction.y);
}

/*
- We are doing the initial set up for the dda
- dda algorithm will jump one square in each loop eiter in a x or y direction
- ray->side_dist.x or y = distance from the ray start position to the
	next x or y position
- if x or y < 0 go the next x or y to the left
- if x or y > 0 go the next x or y to the right
*/

static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->position.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player->position.x) * ray->delta_dist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->position.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->position.y) * ray->delta_dist.y;
	}
}

/*
- We implement the DDA algorithm -> the loop will increment 1 square 
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/

static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map.y < 0.25
			|| ray->map.x < 0.25
			|| ray->map.y > data->map.size.y - 0.25
			|| ray->map.x > data->map.size.x - 1.25)
			break ;
		else if (data->map.map_mtx[(int)ray->map.y][(int)ray->map.x] > '0')
			hit = 1;
	}
}

static void	calculate_line_height(t_ray *ray, t_player *player, t_data *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->position.y + ray->wall_dist * ray->direction.y;
	else
		ray->wall_x = player->position.x + ray->wall_dist * ray->direction.x;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycasting(t_player *player, t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = data->ray; 
	while (x < data->win_width)
	{
		init_raycasting_info(x, &ray, player, data);
		set_dda(&ray, player);
		perform_dda(data, &ray);
		calculate_line_height(&ray, player, data);
		update_pixels(data, &data->textures, &ray, x);
		x++;
	}
	return (0);
}
