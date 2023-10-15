/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:27:47 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 18:01:02 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define TIMES 255.999
# define pi 3.1415926535897932385

typedef struct s_vec t_coor;
typedef struct s_vec t_vec;
typedef struct s_vec t_point;
typedef struct s_vec t_color;

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_element
{
	int				FOV;
	double			light_ratio;
	t_coor			view_coor;
	t_coor			light_coor;
	t_coor			vector_coor;
	t_color			rgb;
	unsigned int	color;
}t_element;

typedef struct s_object
{
	double			diameter;
	double			height;
	t_coor			coor;
	t_coor			vector_coor;
	t_color			rgb;
	unsigned int	color;
}t_object;

typedef struct s_ray
{
	t_point	orig;
	t_vec	dir;
}t_ray;

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
	double	viewport_w;
	double	viewport_h;
	double	focal_len;
	t_point	orig;
	t_vec	horizontal;
	t_vec	vertical;
	t_point	lower_left_corner;
	// t_point	lookfrom;
	// t_point	lookat;
	// t_vec	vup;
}t_camera;

typedef struct s_sphere
{
	t_point	center;
	double	radius;
}t_sphere;
typedef struct s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fd;
	t_element	A;
	t_element	SR;
	t_element	C;
	t_element	L;
	t_object	sp;
	t_object	pl;
	t_object	cy;
	t_object	co;
	t_image		img;
	t_camera	cam;
}t_info;


#endif