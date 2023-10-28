/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:27:47 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 15:53:19 by eunwolee         ###   ########.fr       */
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

typedef enum e_type
{
	SP,
	PL,
	CY,
	CO,
	LIGHT
}t_type;

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
}t_camera;

typedef struct s_light
{
	t_point	point;
	t_color	color;
	double	ratio;
}t_light;

typedef struct s_object
{
	int		type;
	int		num;
	void	*obj;
	void	*next;
}t_object;

typedef struct s_hit_record
{
	t_point	p;
	t_vec	n;
	double	t;
	double	t_min;
	double	t_max;
	t_bool	front_face;
	t_color	color;
}t_hit_record;

typedef struct s_scene
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				fd;
	t_color			ambient;
	double			specular_ratio;
	t_ray			ray;
	t_hit_record	rec;
	t_camera		cam;
	t_image			img;
	t_object		*world;
	t_object		*light;
}t_scene;

#endif