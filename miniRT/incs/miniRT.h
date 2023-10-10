/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:12:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/01 20:44:42 by eunwolee         ###   ########.fr       */
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

t_info	*init_info(int argc, char *file_neme);
t_bool	read_info(t_info *info);

t_bool	create_mlx(t_info *info);

t_bool	check_argument(t_info *info, int argc, char *file_name);

t_bool	check_ratio(double ratio);
t_bool	check_rgb(t_rgb rgb);
t_bool	check_vector(t_coor vector);
t_bool	check_FOV(int FOV);

t_bool	set_func(t_info *info, char **strs);
t_bool	set_rgb(t_rgb *rgb, char **strs);
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

void	print_infos(t_info *info);

#endif