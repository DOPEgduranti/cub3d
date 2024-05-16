/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturegen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:18:40 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 13:05:32 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

t_textures	texturegen(char **map, t_data *data)
{
	t_textures	txtr;
	int			i;
	int			j;
	char		*tmp;

	i = -1;
	while (map && map[++i] && i < 6)
	{
		tmp = ft_strtrim(map[i], " \f\n\r\t\v");
		if (ft_strncmp(tmp, "NO", 2) == 0 && ft_isspace(tmp[2]))
		{
			j = 2;
			while (ft_isspace(tmp[j++]));
			txtr.north = imggen(data, &tmp[j]);
		}
	}
	return (txtr);
}