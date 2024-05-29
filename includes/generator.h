/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/29 11:23:38 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# include <utils.h>

typedef enum e_textnbr
{
	NOTHING = -1,
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_textnbr;

// datagen.c
t_data	datagen(char *mapname);

// mapgen.c
t_map	mapgen(t_data *data);

// texturegen.c
t_textures	texturegen(char **map, t_data *data);

// texturegen_utils.c
t_textnbr	txtr_row(char *str);
int			*txtr_imgset(char *str, t_data *data, char **name);
t_color		txtr_colorset(char *str);
bool		txtr_check(t_textures *txtr);

// player_init.c
void	player_init(t_data *data);

#endif
