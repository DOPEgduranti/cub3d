/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:20:09 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/16 16:07:22 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <utils.h>

int	ft_close_window(t_data *data);
int	ft_keyHook(int keysym, t_data *data);
int	ft_mouseHook(int button, t_data *data);
void	ft_mlx_hook(t_data *data);

#endif