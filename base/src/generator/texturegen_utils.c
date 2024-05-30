/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturegen_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/29 11:28:51 by sgarigli         ###   ########.fr       */
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

static char	*txtr_nameset(char *str)
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
	return (ft_strncpy(str, i, j));
}

int	*txtr_imgset(char *str, t_data *data, char **name)
{
	t_myImg	tmp;
	int		*dst;
	int		x;
	int		y;

	*name = txtr_nameset(str);
	tmp = myimg_gen(*name, data);
	if (!tmp.addr)
		return (NULL);
	dst = ft_calloc(TXTR_SIZE * TXTR_SIZE, sizeof(int));
	if (!dst)
		return (err_malloc(), mlx_destroy_image(data->mlx, tmp.img), NULL);
	y = 0;
	while (y < TXTR_SIZE)
	{
		x = 0;
		while (x < TXTR_SIZE)
		{
			dst[y * TXTR_SIZE + x] = tmp.addr[y * TXTR_SIZE + x];
			x++;
		}
		y++;
	}
	return (mlx_destroy_image(data->mlx, tmp.img), dst);
}

t_color	txtr_colorset(char *str)
{
	t_color	color;
	int		i;

	if (!str)
		return ((t_color){0});
	i = 1;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return ((t_color){0});
	color.hex = rgb_to_hex(&str[i], ft_strdup("0x000000"));
	if (!color.hex)
		return ((t_color){0});
	color.value = ft_hextoi(&color.hex[2], ft_strlen(&color.hex[2]));
	return (color);
}

bool	txtr_check(t_textures *txtr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!txtr->txtrs[i] || !txtr->col_ceiling.hex || !txtr->col_floor.hex)
		{
			err_gen("Error\nissue occurs during texture generation\n");
			free_textures(txtr);
			return (false);
		}
		i++;
	}
	return (true);
}
