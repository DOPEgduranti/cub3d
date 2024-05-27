/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:20:09 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/27 16:05:31 by gduranti         ###   ########.fr       */
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