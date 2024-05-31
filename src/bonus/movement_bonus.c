/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:09:24 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/31 11:22:45 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>

void	movement_bonus(t_data *data, int *x, int *y, t_vector old_pos)
{
	int	tmp_x;
	int	tmp_y;

	if (!BONUS)
		return ;
	tmp_x = (int)(data->player.position.x + (data->player.direction.x * 0.30));
	tmp_y = (int)(data->player.position.y + (data->player.direction.y * 0.30));
	if (data->map.map_mtx[tmp_y][tmp_x] == '1')
	{
		data->player.position = old_pos;
		x = 0;
		y = 0;
	}
}
