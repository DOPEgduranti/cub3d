/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:00:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

static char	**map_mtxnoempty(char **mtx)
{
	int		i;
	int		len;
	char	**dst;

	i = 0;
	len = 0;
	if (!mtx || !*mtx)
		return (NULL);
	dst = ft_mtxdup(mtx);
	while (dst && dst[i])
	{
		if (len < (int)ft_strlen(dst[i]))
		{
			len = (int)ft_strlen(dst[i]);
			i = 0;
			continue ;
		}
		while (len != (int)ft_strlen(dst[i]))
			dst[i] = join_char(dst[i], ' ');
		i++;
	}
	return (dst);
}

static bool	map_charchecker(char **mtx, int i, int j, t_data *data)
{
	if (ft_isinset(mtx[i][j], "NSEW"))
	{
		if (data->player.dir != 0)
			return (false);
		data->player.dir = mtx[i][j];
		data->player.position = (t_vector){j + 0.5, i + 0.5};
		mtx[i][j] = '0';
	}
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

static bool	map_parser(char **mtx, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (mtx && mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (!ft_isinset(mtx[i][j], "01NSEW") && !ft_isspace(mtx[i][j]))
				return (false);
			if (!map_charchecker(mtx, i, j, data))
				return (false);
			j++;
		}
		i++;
	}
	if (!ft_isinset(data->player.dir, "NSEW"))
		return (false);
	return (true);
}

static void	map_remove_spaces(char **mtx)
{
	int		i;
	int		j;

	i = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (ft_isspace(mtx[i][j]))
				mtx[i][j] = '1';
			j++;
		}
		i++;
	}
}

t_map	mapgen(t_data *data)
{
	t_map	map;
	int		i;

	i = 0;
	while (data->file_mtx && data->file_mtx[i]
		&& (ft_isemptyline(data->file_mtx[i])
			|| txtr_row(data->file_mtx[i]) != NOTHING))
		i++;
	map.map_mtx = map_mtxnoempty(&(data->file_mtx[i]));
	if (!map.map_mtx)
		return (err_map(), (t_map){0});
	map.size.x = ft_strlen(map.map_mtx[0]);
	map.size.y = ft_mtxlen(map.map_mtx);
	if (map_parser(map.map_mtx, data) == false)
		return (err_map(), ft_freemtx((void **)map.map_mtx), (t_map){0});
	map_remove_spaces (map.map_mtx);
	return (map);
}
