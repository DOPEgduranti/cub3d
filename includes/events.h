/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:20:09 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/27 12:00:08 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <utils.h>

//keyevents.c
int		ft_close_window(t_data *data);
int		ft_keyHook(int keysym, t_data *data);
int		ft_keyReleaseHook(int keysym, t_data *data);
void	ft_movement(t_data *data, int keysym);
void	ft_rotate(t_data *data, int keysym);

//mouseevents.c
int		ft_mouseHook(int button, t_data *data);

//events.c
void	ft_mlx_hook(t_data *data);

#endif