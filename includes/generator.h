/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
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
t_textnbr	txtr_row(char *str);


// player_init.c
void	player_init(t_data *data);

#endif
