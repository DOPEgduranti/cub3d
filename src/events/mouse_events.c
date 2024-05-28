/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	ft_mouseHook(int button, t_data *data)
{
	(void)data;
	printf("Mouse button %d\n", button);
	return (0);
}
