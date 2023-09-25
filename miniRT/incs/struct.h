/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:27:47 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 17:16:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
}t_coor;

typedef struct s_color
{
	int	R;
	int	G;
	int	B;
}t_color;

typedef struct s_element
{
	int		FOV;
	double	light_ratio;
	t_coor	view_coor;
	t_coor	light_coor;
	t_coor	vector_coor;
	t_color	color;
}t_element;

typedef struct s_object
{
	double	diameter;
	double	height;
	t_coor	coor;
	t_coor	vector_coor;
	t_color	color;
}t_object;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	int			fd;
	t_element	A;
	t_element	SR;
	t_element	C;
	t_element	L;
	t_object	sp;
	t_object	pl;
	t_object	cy;
	t_object	co;
}t_info;

#endif