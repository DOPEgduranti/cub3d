/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:01:34 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 15:26:31 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# include <utils.h>

typedef enum e_textnbr
{
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
t_map	mapgen(char *mapname, t_data *data);

// texturegen.c
t_textures	texturegen(char **map, t_data *data);

#endif