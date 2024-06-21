/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/21 11:26:49 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

static void	ft_rotate_left(t_data *data, t_vector o_plane, t_vector o_dir)
{
	data->player.direction.x = o_dir.x * cos(RSPEED * data->player.run) + o_dir.y * sin(RSPEED * data->player.run);
	data->player.direction.y = o_dir.y * cos(RSPEED * data->player.run) - o_dir.x * sin(RSPEED * data->player.run);
	data->player.plane.x = o_plane.x * cos(RSPEED * data->player.run) + o_plane.y * sin(RSPEED * data->player.run);
	data->player.plane.y = o_plane.y * cos(RSPEED * data->player.run) - o_plane.x * sin(RSPEED * data->player.run);
}

static void	ft_rotate_right(t_data *data, t_vector o_plane, t_vector o_dir)
{
	data->player.direction.x = o_dir.x * cos(RSPEED * data->player.run) - o_dir.y * sin(RSPEED * data->player.run);
	data->player.direction.y = o_dir.y * cos(RSPEED * data->player.run) + o_dir.x * sin(RSPEED * data->player.run);
	data->player.plane.x = o_plane.x * cos(RSPEED * data->player.run) - o_plane.y * sin(RSPEED * data->player.run);
	data->player.plane.y = o_plane.y * cos(RSPEED * data->player.run) + o_plane.x * sin(RSPEED * data->player.run);
}

void	ft_rotate(t_data *data)
{
	t_vector	old_plane;
	t_vector	old_dir;

	if (data->player.rotate != 0)
	{
		old_plane.x = data->player.plane.x;
		old_plane.y = data->player.plane.y;
		old_dir.x = data->player.direction.x;
		old_dir.y = data->player.direction.y;
	}
	if (data->player.rotate == -1)
		ft_rotate_left(data, old_plane, old_dir);
	if (data->player.rotate == 1)
		ft_rotate_right(data, old_plane, old_dir);
}

int	ft_topo(int x, int y, t_data *data)
{
	(void)y;
	if (x < WIDTH / 2 + 100 && x > WIDTH / 2 - 100)
		data->player.rotate = 0;
	if (x > WIDTH / 2 + 100)
		data->player.rotate = 1;
	else if (x < WIDTH / 2 - 100)
		data->player.rotate = -1;
	return (1);
}
