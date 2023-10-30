/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:12:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 14:31:17 by eunwolee         ###   ########.fr       */
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
# include "object.h"
# include "message.h"
# include "../mlx/mlx.h"
# include "../Libft/incs/libft.h"

/* parse */
void		parse_func(t_scene *scene, char **strs);
t_bool		parse_color(t_color *color, char **strs);
t_bool		parse_coor(t_vec *coor, char **strs);
t_bool		parse_double(double *d, char *str);

t_bool		check_argument(t_scene *scene, int argc, char *file_name);
t_bool		check_essential(t_scene *scene);

t_bool		check_ratio(double ratio);
t_bool		check_color(t_color color);
t_bool		check_vector(t_vec vector);
t_bool		check_fov(int FOV);
t_bool		check_double_char(char *str);

/* scene */
t_scene		*scene_init(int argc, char *file_neme);
void		scene_read(t_scene *scene);

void		cam(t_scene *scene, char **strs);
void		cam_set(t_scene *scene);

void		img_set(t_scene *scene);
void		img_ptr_set(t_scene *scene);

/* render */
t_bool		mlx_set_ptr(t_scene *scene);
void		mlx_set_loop(t_scene *scene);

void		draw_loop(t_scene *scene);

t_point		ray_at(t_ray ray, double t);
t_ray		ray_first(t_scene *scene, double u, double v);
t_color		ray_color(t_scene *scene);

t_bool		hit(t_object *world, t_ray ray, t_hit_record *rec);
t_bool		hit_set_func(t_object *obj, t_ray ray, t_hit_record *rec);

/* vector */
t_vec		vec(double x, double y, double z);

t_vec		vec_plus(t_vec vec, double t);
t_vec		vec_minus(t_vec vec, double t);
t_vec		vec_multi(t_vec vec, double t);
t_vec		vec_divide(t_vec vec, double t);

t_vec		vec_plus2(t_vec vec1, t_vec vec2);
t_vec		vec_minus2(t_vec vec1, t_vec vec2);
t_vec		vec_multi2(t_vec vec1, t_vec vec2);
t_vec		vec_divide2(t_vec vec1, t_vec vec2);

double		vec_len_squared(t_vec vec);
double		vec_len(t_vec vec);
t_vec		vec_unit(t_vec vec);

double		vec_dot(t_vec vec1, t_vec vec2);
t_vec		vec_cross(t_vec vec1, t_vec vec2);

/* color */
t_color		color(double R, double G, double B);
int			color_to_int(int t, int r, int g, int b);
t_color		color_to_albedo(t_color color);

/* light */
void		light(t_scene *scene, char **strs);
t_color		light_phong(t_scene *scene);

void		ambient(t_scene *scene, char **strs);

void		specular(t_scene *scene, char **strs);
t_color		specular_get(t_scene *scene, t_vec light_dir);

t_bool		shadow(t_object *world, t_ray light_ray, double light_len);

/* object */
t_sphere	*sphere(char **strs);
t_bool		sphere_hit(t_sphere *sp, t_ray ray, t_hit_record *rec);

t_plane		*plane(char **strs);
t_bool		plane_hit(t_plane *pl, t_ray ray, t_hit_record *rec);

t_cylinder	*cylinder(char **strs);
t_bool		cylinder_hit(t_cylinder *cy, t_ray ray, t_hit_record *rec);

t_cone		*cone(char **strs);
t_bool		cone_hit(t_cone *co, t_ray ray, t_hit_record *rec);

void		rec_init(t_hit_record *rec);
void		rec_set(t_ray ray, t_hit_record *rec, double t, t_color color);
void		set_face_n(t_ray r, t_hit_record *rec);
t_bool		check_t_range(t_hit_record *rec, t_discriminant *d);

/* list */
t_object	*object(void *content, int type);
int			ft_lstsize(t_object *lst);
void		ft_lstadd_back(t_object **lst, t_object *new);
t_object	*ft_lstlast(t_object *lst);

/* util */
int			cnt_strs(char **strs);
void		print_error_exit(char *str);
void		free_double_pointer(char **strs);

#endif