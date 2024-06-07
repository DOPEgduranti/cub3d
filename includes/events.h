/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/07 09:34:13 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <utils.h>
# include <graphic.h>

// events.c
void	ft_mlx_hook(t_data *data);

// keyevents.c
int		ft_close_window(t_data *data);
int		ft_key_press(int keysym, t_data *data);
int		ft_key_release(int keysym, t_data *data);
void	ft_removeexplosion(t_data *data);

// movement.c
int		ft_movement(t_data *data);

// rotation.c
void	ft_rotate(t_data *data);
int		ft_topo(int x, int y, t_data *data);

#endif
