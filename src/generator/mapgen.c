/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:56 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 12:51:22 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

char	**map_mtxnoempty(char **mtx)
{
	int	i;
	int	len;
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

bool	map_charcheck(char **mtx)
{
	(void)(mtx);
	return (false);
}

char	**map_parser(char **mtx, t_data *data)
{
	char	**dst;

	(void)data;
	dst = map_mtxnoempty(mtx);
	if (map_charcheck(dst) == false)
		return (ft_freemtx(&dst), NULL);
	return (dst);
}

t_map	mapgen(t_data *data)
{
	t_map	map;
	int		i;

	i = 0;
	map.textures = texturegen(data->file_mtx, data);
	if (map.textures.col_ceiling == NULL)
		return ((t_map){0});
	while (data->file_mtx && data->file_mtx[i] && (ft_isemptyline(data->file_mtx[i]) || txtr_row(data->file_mtx[i]) != NOTHING))
		i++;
	map.map_mtx = map_parser(&(data->file_mtx[i]), data);
	if(!map.map_mtx)
		return ((t_map){0});
	return (map);
}
