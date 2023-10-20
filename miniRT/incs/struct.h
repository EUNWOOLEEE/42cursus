/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:27:47 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 16:32:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define TIMES 255.999
# define pi 3.1415926535897932385
# define EPSILON 0.000001

# include "component.h"
typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_image
{
	double	aspect_ratio;
	int		w;
	int		h;
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}t_image;

typedef struct s_camera
{
	int		FOV;
	t_point	orig;
	t_vec	dir;
	double	viewport_w;
	double	viewport_h;
	double	focal_len;
	t_vec	horizontal;
	t_vec	vertical;
	t_point	llc;
	t_vec	vec_up;
	t_vec	vec_right;
}t_camera;

typedef struct s_light
{
	t_point	point;
	double	ratio;
	t_color	color;
}t_light;

typedef enum e_type
{
	SP,
	PL,
	CY,
	CO,
	L
}t_type;

typedef struct s_object
{
	int		type;
	void	*obj;
	void	*next;
	t_color	albedo;
}t_object;

typedef struct s_hit_record
{
	t_point	p;
	t_vec	n;
	double	t;
	double	t_min;
	double	t_max;
	t_bool	front_face;
	t_color	albedo;
}t_hit_record;

typedef struct s_scene
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fd;
	t_ray		ray;
	t_hit_record	rec;
	t_color		amb;
	t_camera	cam;
	t_image		img;
	t_object	*world;
	t_object	*light;
}t_scene;

#endif