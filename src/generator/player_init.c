/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

static void	player_no_so(t_player *player)
{
	if (player->dir == 'N')
	{
		player->direction.x = 0;
		player->direction.y = -1;
		player->plane.x = ((double)HEIGHT / (double)WIDTH);
		player->plane.y = 0;
	}
	else if (player->dir == 'S')
	{
		player->direction.x = 0;
		player->direction.y = 1;
		player->plane.x = -((double)HEIGHT / (double)WIDTH);
		player->plane.y = 0;
	}
}

static void	player_ea_we(t_player *player)
{
	if (player->dir == 'E')
	{
		player->direction.x = 1;
		player->direction.y = 0;
		player->plane.x = 0;
		player->plane.y = ((double)HEIGHT / (double)WIDTH);
	}
	else if (player->dir == 'W')
	{
		player->direction.x = -1;
		player->direction.y = 0;
		player->plane.x = 0;
		player->plane.y = -((double)HEIGHT / (double)WIDTH);
	}
}

void	player_init(t_data *data)
{
	player_no_so(&data->player);
	player_ea_we(&data->player);
}
