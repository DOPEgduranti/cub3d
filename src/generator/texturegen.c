/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturegen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:18:40 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 16:43:15 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

t_textnbr	txtr_row(char *str)
{
	if (!str)
		return (-1);
	if (ft_strncmp(str, "NO", 2) == 0 && ft_isspace(str[2]))
		return (NO);
	else if (ft_strncmp(str, "SO", 2) == 0 && ft_isspace(str[2]))
		return (SO);
	else if (ft_strncmp(str, "WE", 2) == 0 && ft_isspace(str[2]))
		return (WE);
	else if (ft_strncmp(str, "EA", 2) == 0 && ft_isspace(str[2]))
		return (EA);
	else if (str[0] == 'F' && ft_isspace(str[1]))
		return (F);
	else if (str[0] == 'C' && ft_isspace(str[1]))
		return (C);
	return (-1);
}

t_img	*txtr_imgset(char *str, t_data *data)
{
	int	i;
	if (!str)
		return (NULL);
	i = 0;
	while (ft_isalpha(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	return (imggen(data, &str[i]));
}

char	*txtr_colorset(char *str)
{
	int	i;
	if (!str)
		return (NULL);
	i = 0;
	while (ft_isalpha(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	return (ft_strdup(&(str[i])));
}

t_textures	texturegen(char **map, t_data *data)
{
	t_textures	txtr;
	int			i;
	char		*tmp;

	i = -1;
	txtr = (t_textures){0};
	while (map && map[++i])
	{
		tmp = ft_strtrim(map[i], " \f\n\r\t\v");
		if (txtr_row(tmp) == NO)
			txtr.north = txtr_imgset(tmp, data);
		else if (txtr_row(tmp) == SO)
			txtr.south = txtr_imgset(tmp, data);
		else if (txtr_row(tmp) == WE)
			txtr.west = txtr_imgset(tmp, data);
		else if (txtr_row(tmp) == EA)
			txtr.east = txtr_imgset(tmp, data);
		else if (txtr_row(tmp) == F)
			txtr.col_floor = txtr_colorset(tmp);
		else if (txtr_row(tmp) == C)
			txtr.col_ceiling = txtr_colorset(tmp);
		free(tmp);
	}
	return (txtr);
}
