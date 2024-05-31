/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/31 11:10:54 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>

static bool	ft_empty_tile_check(char **mtx, int i, int j)
{
	if (mtx[i][j] == '0')
	{
		if (i == 0 || j == 0 || !mtx[(i + 1)] || !mtx[i][j + 1])
			return (false);
		if (ft_isspace(mtx[i + 1][j]))
			return (false);
		if (ft_isspace(mtx[i - 1][j]))
			return (false);
		if (ft_isspace(mtx[i][j + 1]))
			return (false);
		if (ft_isspace(mtx[i][j - 1]))
			return (false);
	}
	return (true);
}

static bool	ft_door_check(char **mtx, int i, int j)
{
	char	c;

	if (mtx[i][j] == 'D')
	{
		if (i == 0 || j == 0 || !mtx[(i + 1)] || !mtx[i][j + 1])
			return (false);
		if (mtx[i + 1][j] != mtx[i - 1][j] || !ft_isinset(mtx[i + 1][j], "10"))
			return (false);
		else
			c = mtx[i + 1][j];
		if (mtx[i][j + 1] != mtx[i][j - 1] || !ft_isinset(mtx[i][j + 1], "10"))
			return (false);
		else if (mtx[i][j + 1] == c)
			return (false);
	}
	return (true);
}

bool	map_check_bonus(char **mtx, int i, int j, t_data *data)
{
	if (!ft_isinset(mtx[i][j], "01NSEWD") && !ft_isspace(mtx[i][j]))
		return (false);
	if (ft_isinset(mtx[i][j], "NSEW"))
	{
		if (data->player.dir != 0)
			return (false);
		data->player.dir = mtx[i][j];
		data->player.position = (t_vector){j + 0.5, i + 0.5};
		mtx[i][j] = '0';
	}
	if (!ft_empty_tile_check(mtx, i, j) || !ft_door_check(mtx, i, j))
		return (false);
	return (true);
}
