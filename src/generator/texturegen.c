/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturegen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/05 12:36:00 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

static void	txtr_bonus(t_data *data, t_textures *txtr)
{
	if (!BONUS)
		return ;
	txtr->txtrs[DOOR] = txtr_imgset("D ./assets/texture/txtr26.xpm",
			data, &txtr->door);
	txtr->txtrs[BOX] = txtr_imgset("D ./assets/texture/box.xpm",
			data, &txtr->door);
	txtr->txtrs[WEAPON1] = txtr_imgset("FO ./assets/sprites/Yellow1.xpm",
			data, &txtr->door);
	txtr->txtrs[WEAPON2] = txtr_imgset("FO ./assets/sprites/Yellow2.xpm",
			data, &txtr->door);
	txtr->txtrs[WEAPON3] = txtr_imgset("FO ./assets/sprites/Yellow3.xpm",
			data, &txtr->door);
	txtr->txtrs[WEAPON4] = txtr_imgset("FO ./assets/sprites/Yellow4.xpm",
			data, &txtr->door);
}

static void	txtr_set(char **map, t_data *data, t_textures *txtr)
{
	int		i;
	char	*tmp;

	i = -1;
	while (map && map[++i])
	{
		tmp = ft_strtrim(map[i], " \f\n\r\t\v");
		if (txtr_row(tmp) == NO && !txtr->north)
			txtr->txtrs[NORTH] = txtr_imgset(tmp, data, &txtr->north);
		else if (txtr_row(tmp) == SO && !txtr->south)
			txtr->txtrs[SOUTH] = txtr_imgset(tmp, data, &txtr->south);
		else if (txtr_row(tmp) == WE && !txtr->west)
			txtr->txtrs[WEST] = txtr_imgset(tmp, data, &txtr->west);
		else if (txtr_row(tmp) == EA && !txtr->east)
			txtr->txtrs[EAST] = txtr_imgset(tmp, data, &txtr->east);
		else if (txtr_row(tmp) == F && !txtr->col_floor.hex)
			txtr->col_floor = txtr_colorset(tmp);
		else if (txtr_row(tmp) == C && !txtr->col_ceiling.hex)
			txtr->col_ceiling = txtr_colorset(tmp);
		free(tmp);
	}
	txtr_bonus(data, txtr);
}

t_textures	texturegen(char **map, t_data *data)
{
	t_textures	txtr;

	txtr = (t_textures){0};
	txtr.size = TXTR_SIZE;
	txtr.txtrs = ft_calloc(NBR_TEXTURE, sizeof(int *));
	if (!txtr.txtrs)
		return (err_malloc(), (t_textures){0});
	txtr_set(map, data, &txtr);
	if (txtr_check(&txtr) == false)
		return ((t_textures){0});
	return (txtr);
}
