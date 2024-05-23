/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:31:14 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/22 15:23:11 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

static void	init_player_north_south(t_player *player)
{
	if (player->dir == 'S')
	{
		player->direction.x = 0;
		player->direction.y = 1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (player->dir == 'N')
	{
		player->direction.x = 0;
		player->direction.y = -1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else
		return ;
}

static void	init_player_east_west(t_player *player)
{
	if (player->dir == 'W')
	{
		player->direction.x = -1;
		player->direction.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->direction.x = 1;
		player->direction.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else
		return ;
}

void	init_player_direction(t_data *data)
{
	init_player_north_south(&data->player);
	init_player_east_west(&data->player);
}
