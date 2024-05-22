/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturegen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:18:40 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/22 11:34:02 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

t_textnbr	txtr_row(char *str)
{
	if (!str)
		return (NOTHING);
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
	return (NOTHING);
}

char	*txtr_nameset(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && ft_isalpha(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	j = i;
	while (str[j] && !ft_isspace(str[j]))
		j++;
	return(ft_strncpy(str, i, j));
}

int	*txtr_imgset(char *str, t_data *data, t_textures *txtr, char **name)
{
	t_myImg	tmp;
	int		*dst;
	int		x;
	int		y;

	*name = txtr_nameset(str);
	tmp = myImggen(*name, data);
	if (!tmp.addr)
		return (NULL);
	dst = ft_calloc(txtr->size * txtr->size, sizeof(int));
	if (!dst)
		return (mlx_destroy_image(data->mlx, tmp.img), free(tmp.addr), NULL);
	y = 0;
	while (y < txtr->size)
	{
		x = 0;
		while (x < txtr->size)
		{
			dst[y * txtr->size + x] = tmp.addr[y * txtr->size + x];
			x++;
		}
		y++;
	}
	return (mlx_destroy_image(data->mlx, tmp.img), free(tmp.addr), dst);
}

t_color	txtr_colorset(char *str)
{
	t_color	color;
	int	i;

	if (!str)
		return ((t_color){0});
	i = 1;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return ((t_color){0});
	color.hex = rgb_to_hex(&str[i], ft_strdup("0x000000"));
	color.value = ft_hextoi(&color.hex[2], ft_strlen(&color.hex[2]));
	return (color);
}

t_textures	texturegen(char **map, t_data *data)
{
	t_textures	txtr;
	int			i;
	char		*tmp;

	i = -1;
	txtr = (t_textures){0};
	txtr.size = TXTR_SIZE;
	txtr.txtrs = malloc(5 * sizeof(int *));
	if (!txtr.txtrs)
		return ((t_textures){0});
	while (map && map[++i])
	{
		tmp = ft_strtrim(map[i], " \f\n\r\t\v");
		if (txtr_row(tmp) == NO)
			txtr.txtrs[NORTH] = txtr_imgset(tmp, data, &txtr, &txtr.north);
		else if (txtr_row(tmp) == SO)
			txtr.txtrs[SOUTH] = txtr_imgset(tmp, data, &txtr, &txtr.south);
		else if (txtr_row(tmp) == WE)
			txtr.txtrs[WEST] = txtr_imgset(tmp, data, &txtr, &txtr.west);
		else if (txtr_row(tmp) == EA)
			txtr.txtrs[EAST] = txtr_imgset(tmp, data, &txtr, &txtr.east);
		else if (txtr_row(tmp) == F)
			txtr.col_floor = txtr_colorset(tmp);
		else if (txtr_row(tmp) == C)
			txtr.col_ceiling = txtr_colorset(tmp);
		free(tmp);
	}
	return (txtr);
}
