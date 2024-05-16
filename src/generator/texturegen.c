/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturegen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:18:40 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 11:45:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

t_textures	texturegen(char **map)
{
	t_textures	txtr;
	int			i;

	i = 0;
	while (map && map[i++]);
	if (i < 6)
		return (gerr("Error: texturegen"), (t_textures){0});
	if (ft_strncmp(map[0], "NO ", 3) == 0)
		txtr.north = ft_strdup(&map[0][3]);
	if (ft_strncmp(map[1], "SO ", 3) == 0)
		txtr.north = ft_strdup(&map[0][3]);
	if (ft_strncmp(map[2], "WE ", 3) == 0)
		txtr.north = ft_strdup(&map[0][3]);
	if (ft_strncmp(map[3], "EA ", 3) == 0)
		txtr.north = ft_strdup(&map[0][3]);
	if (ft_strncmp(map[4], "F ", 2) == 0)
		txtr.north = ft_strdup(&map[0][3]);
	if (ft_strncmp(map[5], "C ", 2) == 0)
		txtr.north = ft_strdup(&map[0][3]);
	return (txtr);
}