/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:18 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 10:58:41 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <core.h>

// debug.c
void	ft_printmtx(char **mtx);

// dup_funct.c
char	**ft_mtxdup(char **mtx);

// error.c
int	gerr(char *str);

// img.c
t_img	*imggen(t_data *data, char *filename);

// is_funct.c
bool	ft_isspace(char c);
bool	ft_isemptyline(char *str);

// size_funct.c
int	ft_mtxlen(char **mtx);

#endif