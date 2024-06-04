/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:56:19 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/04 11:13:20 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>

void	dda_bonus(t_data *data)
{
	if (!BONUS)
		return ;
	data->ray.door = false;
	if (data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
		== 'D')
	{
		data->ray.door = true;
		data->ray.hit = true;
	}
	if (data->map.map_mtx[(int)data->ray.map.y][(int)data->ray.map.x]
		== 'F')
		data->ray.foe = true;
}
