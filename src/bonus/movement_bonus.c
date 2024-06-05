/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:09:24 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/05 12:05:05 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>
#include <graphic.h>

void	ft_door(t_data *data)
{
	int	y;
	int	x;

	if (!BONUS)
		return ;
	y = data->player.position.y + data->player.direction.y;
	x = data->player.position.x + data->player.direction.x;
	if (data->map.map_mtx[y][x] == 'D')
		data->map.map_mtx[y][x] = 'O';
	else if (data->map.map_mtx[y][x] == 'O')
		data->map.map_mtx[y][x] = 'D';
	else
		return ;
	render(data);
}

void	movement_bonus(t_data *data, int *x, int *y, t_vector old_pos)
{
	int	tmp_x;
	int	tmp_y;

	if (!BONUS)
		return ;
	tmp_x = (int)(data->player.position.x);
	tmp_y = (int)(data->player.position.y);
	if (data->map.map_mtx[tmp_y][tmp_x] == '1'
		|| data->map.map_mtx[tmp_y][tmp_x] == 'D'
		|| data->map.map_mtx[tmp_y][tmp_x] == 'B')
	{
		data->player.position = old_pos;
		x = 0;
		y = 0;
	}
}
