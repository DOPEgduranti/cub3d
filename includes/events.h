/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:20:09 by sgarigli          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/16 16:07:22 by sgarigli         ###   ########.fr       */
=======
/*   Updated: 2024/05/20 10:30:45 by sgarigli         ###   ########.fr       */
>>>>>>> 361e6247634075974bcfa3f4dfeb389722b98dc1
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <utils.h>

<<<<<<< HEAD
int	ft_close_window(t_data *data);
int	ft_keyHook(int keysym, t_data *data);
int	ft_mouseHook(int button, t_data *data);
=======
//keyevents.c
int		ft_close_window(t_data *data);
int		ft_keyHook(int keysym, t_data *data);

//mouseevents.c
int		ft_mouseHook(int button, t_data *data);

//events.c
>>>>>>> 361e6247634075974bcfa3f4dfeb389722b98dc1
void	ft_mlx_hook(t_data *data);

#endif