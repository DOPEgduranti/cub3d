/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 16:07:52 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

static void	ft_move_up(t_data *data, int *y)
{
	data->player.position.x += data->player.direction.x * MSPEED;
	data->player.position.y += data->player.direction.y * MSPEED;
	(*y)++;
}

static void	ft_move_down(t_data *data, int *y)
{
	data->player.position.x -= data->player.direction.x * MSPEED;
	data->player.position.y -= data->player.direction.y * MSPEED;
	(*y)--;
}

static void	ft_move_left(t_data *data, int *x)
{
	data->player.position.x += data->player.direction.y * MSPEED;
	data->player.position.y -= data->player.direction.x * MSPEED;
	(*x)--;
}

static void	ft_move_right(t_data *data, int *x)
{
	data->player.position.x -= data->player.direction.y * MSPEED;
	data->player.position.y += data->player.direction.x * MSPEED;
	(*x)++;
}

int	ft_movement(t_data *data)
{
	int			x;
	int			y;
	t_vector	old_pos;

	x = 0;
	y = 0;
	old_pos = data->player.position;
	if (data->player.move.y == 1)
		ft_move_up(data, &y);
	if (data->player.move.y == -1)
		ft_move_down(data, &y);
	if (data->player.move.x == 1)
		ft_move_right(data, &y);
	if (data->player.move.x == -1)
		ft_move_left(data, &y);
	if (BONUS && data->map.map_mtx[(int)data->player.position.y]
		[(int)data->player.position.x] == '1')
	{
		data->player.position = old_pos;
		x = 0;
		y = 0;
	}
	ft_rotate(data);
	return (abs(x) + abs(y) + abs(data->player.rotate));
}
