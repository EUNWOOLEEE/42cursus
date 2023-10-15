/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:12:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 17:26:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "struct.h"
# include "message.h"
# include "../mlx/mlx.h"
# include "../Libft/incs/libft.h"

t_info	*info_init(int argc, char *file_neme);
t_bool	info_read(t_info *info);

t_bool	mlx_set(t_info *info);

t_bool	check_argument(t_info *info, int argc, char *file_name);

t_bool	check_ratio(double ratio);
t_bool	check_rgb(t_color rgb);
t_bool	check_vector(t_coor vector);
t_bool	check_FOV(int FOV);

t_bool	set_func(t_info *info, char **strs);
t_bool	set_rgb(t_color *rgb, char **strs);
t_bool	set_coor(t_coor *coor, char **strs);
int		set_color(int t, int r, int g, int b);

t_bool	emt_A(t_element *A, char **strs);
t_bool	emt_SR(t_element *SR, char **strs);
t_bool	emt_C(t_element *C, char **strs);
t_bool	emt_L(t_element *L, char **strs);

t_bool	obj_sp(t_object *sp, char **strs);
t_bool	obj_pl(t_object *pl, char **strs);
t_bool	obj_cy(t_object *cy, char **strs);
t_bool	obj_co(t_object *co, char **strs);

int		cnt_strs(char **strs);
void	free_double_pointer(char **strs);
t_bool	print_error_return(char *str);
double	degrees_to_radians(t_info *info);

void	print_infos(t_info *info);


void	my_mlx_pixel_put(t_info *info, int x, int y, int color);
void	img_draw_to_window(t_info *info);

void	img_set(t_info *info);
void	img_ptr_set(t_info *info);

void	cam_set(t_info *info);

t_vec	vec_set(double x, double y, double z);
t_vec	vec_n_vec_set(t_vec vec);
t_vec	vec_cal(t_vec vec, double value, char operator);
t_vec	vec_n_vec_cal(t_vec vec1, t_vec vec2, char operator);

double	vec_len_squared(t_vec vec);
double	vec_len(t_vec vec);
t_vec	vec_unit(t_vec vec);

t_color	rgb_cal(t_color rgb, double value, char operator);
t_color	rgb_n_rgb_cal(t_color rgb1, t_color rgb2, char operator);
void	rgb_set(t_color *rgb, double R, double G, double B);
void	rgb_n_rgb_set(t_color *rgb1, t_color rgb2);

t_point	ray_at(t_ray ray, double t);
t_ray	ray_first(t_info *info, double u, double v);
t_color ray_color(t_ray r);

#endif