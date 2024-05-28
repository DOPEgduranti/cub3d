/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:06 by gduranti         ###   ########.fr       */
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
int	err_gen(char *str);
int	err_malloc(void);
int	err_map(void);

// free_funct.c
void	free_textures(t_textures *txtr);
void	free_map(t_map *map);
void	free_data(t_data *data);

// img.c
t_img	*imggen(t_data *data, char *filename);
t_myImg	myimg_gen(char *filename, t_data *data);
t_myImg	myimg_empty(t_data *data, int width, int height);
void	set_pixel(t_myImg *image, int x, int y, int color);

// is_funct.c
bool	ft_isspace(char c);
bool	ft_isemptyline(char *str);
bool	ft_isinset(char c, char *set);

// size_funct.c
int	ft_mtxlen(char **mtx);

#endif
