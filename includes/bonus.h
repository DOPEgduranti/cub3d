/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/03 11:50:42 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <utils.h>

void	ft_ciao(void);

// map_bonus.c
bool	map_check_bonus(char **mtx, int i, int j, t_data *data);

// minimap_bonus.c
void	render_minimap(t_myImg *img, t_data *data);

// movement_bonus.c
void	ft_door(t_data *data);
void	movement_bonus(t_data *data, int *x, int *y, t_vector old_pos);

// raycast_bonus.c
void	dda_bonus(t_data *data);

#endif
