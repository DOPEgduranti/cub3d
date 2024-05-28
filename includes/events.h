/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <utils.h>
# include <graphic.h>

//keyevents.c
int		ft_close_window(t_data *data);
int		ft_keyHook(int keysym, t_data *data);
int		ft_keyReleaseHook(int keysym, t_data *data);
int		ft_movement(t_data *data);
void	ft_rotate(t_data *data);

//mouseevents.c
int		ft_mouseHook(int button, t_data *data);

//events.c
void	ft_mlx_hook(t_data *data);

#endif
