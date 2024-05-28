/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:31:14 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 09:59:40 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

static void	player_no_so(t_player *player)
{
	if (player->dir == 'N')
	{
		player->direction.x = 0;
		player->direction.y = -1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (player->dir == 'S')
	{
		player->direction.x = 0;
		player->direction.y = 1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
}

static void	player_we_ea(t_player *player)
{
	if (player->dir == 'E')
	{
		player->direction.x = 1;
		player->direction.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else if (player->dir == 'W')
	{
		player->direction.x = -1;
		player->direction.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
}

void	player_init(t_data *data)
{
	player_no_so(&data->player);
	player_we_ea(&data->player);
}
