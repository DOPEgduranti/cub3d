/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:18 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/21 11:49:04 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <core.h>

//conversion.c
void	ft_itohex(int dec, char *hex, int *index);
int		*find_rgb(char	*str);
char	*rgb_to_hex(char *str, char *hex);
int		ft_hextoi(char *hex, int length);

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