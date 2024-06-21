/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/21 15:41:41 by gduranti         ###   ########.fr       */
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

// mana.c

void	reduce_mana(t_data *data);
void	regain_mana(t_data *data);

// movement.c
int		ft_movement(t_data *data);

// rotation.c
void	ft_rotate(t_data *data);
int		ft_topo(int x, int y, t_data *data);

// run.c

void	ft_run(t_data *data);
void 	reduce_stamina(t_data *data);
void 	regain_stamina(t_data *data);
void	cast_spell(double *mana);

#endif
