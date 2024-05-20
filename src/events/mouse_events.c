/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:25:49 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/16 15:54:21 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	ft_mouseHook(int button, t_data *data)
{
	(void)data;
	printf("Mouse button %d\n", button);
	return (0);
}