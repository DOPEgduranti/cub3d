/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx_hook.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Thu Aug  3 11:49:06 2000 Charlie Root
** Last update Fri Jan 28 17:05:28 2005 Olivier Crouzet
*/


#include	"mlx_int.h"




int	mlx_hook(t_win_list *win, int x_event, int x_mask, 
		 int (*funct)(),void *param)
{
  win->hooks[x_event].hook = funct;
  win->hooks[x_event].param = param;
  win->hooks[x_event].mask = x_mask;
}


int	mlx_do_key_autorepeatoff(t_xvar *xvar)
{
  XAutoRepeatOff(xvar->display);
}

int	mlx_do_key_autorepeaton(t_xvar *xvar)
{
  XAutoRepeatOn(xvar->display);
}


int	mlx_do_sync(t_xvar *xvar)
{
  XSync(xvar->display, False);
}
