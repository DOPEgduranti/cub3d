/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:18 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 16:17:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <core.h>

// error.c
int	gerr(char *str);

// img.c
t_img	*imggen(t_data *data, char *filename);

// is_funct.c
bool	ft_isspace(char c);

#endif