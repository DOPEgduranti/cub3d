/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:25:47 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/28 10:43:40 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	ft_close_window(t_data *data)
{
	free_data(data);
	exit(0);
}

int ft_movement (t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->player.move.y == 1)
	{
		data->player.position.x += data->player.direction.x * MSPEED;
		data->player.position.y += data->player.direction.y * MSPEED;
		y++;
	}
	if (data->player.move.y == -1)
	{
		data->player.position.x -= data->player.direction.x * MSPEED;
		data->player.position.y -= data->player.direction.y * MSPEED;
		y--;
	}
	if (data->player.move.x == -1)
	{
		data->player.position.x += data->player.direction.y * MSPEED;
		data->player.position.y -= data->player.direction.x * MSPEED;
		x--;
	}
	if (data->player.move.x == 1)
	{
		data->player.position.x -= data->player.direction.y * MSPEED;
		data->player.position.y += data->player.direction.x * MSPEED;
		x++;
	}
	ft_rotate(data);
	return (abs(x) + abs(y) + abs(data->player.rotate));
}


void ft_rotate (t_data *data)
{
	if (data->player.rotate == -1)
	{
		double old_plane_x = data->player.plane.x;
		double old_plane_y = data->player.plane.y;
		double old_dir_x = data->player.direction.x;
		double old_dir_y = data->player.direction.y;

		data->player.direction.x = old_dir_x * cos(RSPEED) + old_dir_y * sin(RSPEED);
		data->player.direction.y = old_dir_y * cos(RSPEED) - old_dir_x * sin(RSPEED);
		data->player.plane.x = old_plane_x * cos(RSPEED) + old_plane_y * sin(RSPEED);
		data->player.plane.y = old_plane_y * cos(RSPEED) - old_plane_x * sin(RSPEED);
	}
	if (data->player.rotate == 1)
	{
		double old_plane_x = data->player.plane.x;
		double old_plane_y = data->player.plane.y;
		double old_dir_x = data->player.direction.x;
		double old_dir_y = data->player.direction.y;
		
		data->player.direction.x = old_dir_x * cos(RSPEED) - old_dir_y * sin(RSPEED);
		data->player.direction.y = old_dir_y * cos(RSPEED) + old_dir_x * sin(RSPEED);
		data->player.plane.x = old_plane_x * cos(RSPEED) - old_plane_y * sin(RSPEED);
		data->player.plane.y = old_plane_y * cos(RSPEED) + old_plane_x * sin(RSPEED);
	}
}

int ft_keyReleaseHook(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_s)
		data->player.move.y = 0;
	if (keysym == XK_a || keysym == XK_d)
		data->player.move.x = 0;
	if (keysym == XK_Left || keysym == XK_Right)
		data->player.rotate = 0;
	return (0);
}

int	ft_keyHook(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_close_window(data);
	if (keysym == XK_w)
		data->player.move.y = 1;
	if (keysym == XK_s)
		data->player.move.y = -1;
	if (keysym == XK_a)
		data->player.move.x = -1;
	if (keysym == XK_d)
		data->player.move.x = 1;
	if (keysym == XK_Left)
		data->player.rotate = -1;
	if (keysym == XK_Right)
		data->player.rotate = 1;
	printf("player position: %f %f\n", data->player.position.x, data->player.position.y);
	return (0);
}