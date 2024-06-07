/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/06 16:15:44 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <utils.h>

// map_bonus.c
bool	map_check_bonus(char **mtx, int i, int j, t_data *data);

// minimap_bonus.c
void	render_minimap(t_myImg *img, t_data *data);

// movement_bonus.c
void	ft_door(t_data *data);
void	movement_bonus(t_data *data, int *x, int *y, t_vector old_pos);

// raycast_bonus.c
void	dda_bonus(t_data *data);

// shoot_bonus.c
int		ft_shoot(t_data *data);

// shoot_utils_bonus.c
void	render_shooting(t_myImg *img, t_data *data);

// create_bonus.c
void	ft_createbox(t_data *data);

// sprites_bonus.c
void	render_weapon(t_myImg *img, t_data *data);
void	render_weapon2(t_myImg *img, t_data *data);

#endif
