/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:25:47 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/27 12:32:23 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <cub3d.h>

int	ft_close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

void ft_movement (t_data *data, int keysym)
{
	if (data->player.has_moved == false)
		return ;
	if (keysym == XK_w)
	{
		data->player.position.x += data->player.direction.x * MSPEED;
		data->player.position.y += data->player.direction.y * MSPEED;
	}
	if (keysym == XK_s)
	{
		data->player.position.x -= data->player.direction.x * MSPEED;
		data->player.position.y -= data->player.direction.y * MSPEED;
	}
	if (keysym == XK_a)
	{
		data->player.position.x += data->player.direction.y * MSPEED;
		data->player.position.y -= data->player.direction.x * MSPEED;
	}
	if (keysym == XK_d)
	{
		data->player.position.x -= data->player.direction.y * MSPEED;
		data->player.position.y += data->player.direction.x * MSPEED;
	}
	render_images(data);
}



void ft_rotate (t_data *data, int keysym)
{
	if (data->player.rotate == false)
		return ;
	if (keysym == XK_Left)
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
	if (keysym == XK_Right)
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
	render_images(data);
}

int ft_keyReleaseHook(int keysym, t_data *data)
{
	if(keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
		data->player.has_moved = false;
	if (keysym == XK_Left || keysym == XK_Right)
		data->player.rotate = false;
	return (0);
}

int	ft_keyHook(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_close_window(data);
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
	{
		data->player.has_moved = true;
		ft_movement(data, keysym);
	}
	if (keysym == XK_Left || keysym == XK_Right)
	{
		data->player.rotate = true;
		ft_rotate(data, keysym);
	}
	
	printf("player position: %f %f\n", data->player.position.x, data->player.position.y);
	return (0);
}