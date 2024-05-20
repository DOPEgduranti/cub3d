/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:56 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/20 10:24:51 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

char	**map_mtxnoempty(char **mtx)
{
	int		i;
	int		len;
	char	**dst;

	i = 0;
	len = 0;
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

bool	map_charchecker(char **mtx, t_vector pos, t_data *data)
{
	if (ft_isinset(mtx[(int)pos.y][(int)pos.x], "NSEW"))
	{
		if (data->player.begin_dir == 0)
		{
			data->player.begin_dir = mtx[(int)pos.y][(int)pos.x];
			data->player.position = pos;
		}
		else
			return (false);
	}
	if (mtx[(int)pos.y][(int)pos.x] == '0')
	{
		if (pos.y == 0 || pos.x == 0 || !mtx[(int)(pos.y + 1)] || !mtx[(int)pos.y][(int)pos.x + 1])
			return (false);
		if (mtx[(int)pos.y + 1][(int)pos.x] == ' ')
			return (false);
		if (mtx[(int)pos.y - 1][(int)pos.x] == ' ')
			return (false);
		if (mtx[(int)pos.y][(int)pos.x + 1] == ' ')
			return (false);
		if (mtx[(int)pos.y][(int)pos.x - 1] == ' ')
			return (false);
	}
	return (true);
}

bool	map_parser(char **mtx, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (mtx && mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (!ft_isinset(mtx[i][j], " 01NSEW"))
				return (false);
			if (!map_charchecker(mtx, (t_vector){j, i, 0}, data))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_map	mapgen(t_data *data)
{
	t_map	map;
	int		i;

	i = 0;
	map.textures = texturegen(data->file_mtx, data);
	if (map.textures.north == NULL)
		return ((t_map){0});
	while (data->file_mtx && data->file_mtx[i] && (ft_isemptyline(data->file_mtx[i]) || txtr_row(data->file_mtx[i]) != NOTHING))
		i++;
	map.map_mtx = map_mtxnoempty(&(data->file_mtx[i]));
	if(!map.map_mtx)
		return ((t_map){0});
	map.size.x = ft_strlen(map.map_mtx[0]);
	map.size.y = ft_mtxlen(map.map_mtx);
	if (map_parser(map.map_mtx, data) == false)
		return (ft_freemtx(&map.map_mtx), (t_map){0});
	return (map);
}
