/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:12:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/26 18:17:38 by eunwolee         ###   ########.fr       */
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

int	hit_obj;
int debug;

t_scene	*scene_init(int argc, char *file_neme);
void	scene_read(t_scene *scene);

t_bool	mlx_set(t_scene *scene);

t_bool	check_argument(t_scene *scene, int argc, char *file_name);

t_bool	check_ratio(double ratio);
t_bool	check_color(t_color color);
t_bool	check_vector(t_vec vector);
t_bool	check_FOV(int FOV);

void	parse_func(t_scene *scene, char **strs);
t_bool	parse_color(t_color *color, char **strs);
t_bool	parse_coor(t_vec *coor, char **strs);
t_bool	parse_ratio(double *ratio, char *str);

void	ambient(t_scene *scene, char **strs);
void	specular(t_scene *scene, char **strs);
t_light	*light(char **strs);
t_color	light_phong(t_scene *scene, t_object *lights);
t_bool	shadow(t_object *world, t_ray light_ray, double light_len);

void	cam(t_scene *scene, char **strs);
void	cam_set(t_scene *scene);


int		cnt_strs(char **strs);
void	free_double_pointer(char **strs);
void	print_error_exit(char *str);
double	degrees_to_radians(t_scene *scene);

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color);
void	img_draw_to_window(t_scene *scene);

void	img_set(t_scene *scene);
void	img_ptr_set(t_scene *scene);


//vec
t_vec	vec(double x, double y, double z);

t_vec	vec_plus(t_vec vec, double t);
t_vec	vec_minus(t_vec vec, double t);
t_vec	vec_multi(t_vec vec, double t);
t_vec	vec_divide(t_vec vec, double t);

t_vec	vec_plus2(t_vec vec1, t_vec vec2);
t_vec	vec_minus2(t_vec vec1, t_vec vec2);
t_vec	vec_multi2(t_vec vec1, t_vec vec2);
t_vec	vec_divide2(t_vec vec1, t_vec vec2);

double	vec_len_squared(t_vec vec);
double	vec_len(t_vec vec);
t_vec	vec_unit(t_vec vec);
double	vec_dot(t_vec vec1, t_vec vec2);
t_vec	vec_cross(t_vec vec1, t_vec vec2);


//color
t_color	color(double R, double G, double B);
int		color_to_int(int t, int r, int g, int b);
t_color	color_to_albedo(t_color color);

t_color	color_plus(t_color color, double t);
t_color	color_minus(t_color color, double t);
t_color	color_multi(t_color color, double t);
t_color	color_divide(t_color color, double t);

t_color	color_plus2(t_color color1, t_color color2);
t_color	color_minus2(t_color color1, t_color color2);
t_color	color_multi2(t_color color1, t_color color2);
t_color	color_divide2(t_color color1, t_color color2);


//ray
t_point	ray_at(t_ray ray, double t);
t_ray	ray_first(t_scene *scene, double u, double v);
t_color	ray_color(t_scene *scene);

t_bool	hit(t_object *world, t_ray ray, t_hit_record *rec, t_bool light);
t_bool	hit_set_func(t_object *obj, t_ray ray, t_hit_record *rec);


//object
t_sphere	*sphere(char **strs);
t_bool		sphere_hit(t_sphere *sp, t_ray ray, t_hit_record *rec);

t_plane		*plane(char **strs);
t_bool		plane_hit(t_plane *pl, t_ray ray, t_hit_record *rec);

t_cylinder	*cylinder(char **strs);
int			cylinder_hit(t_cylinder *cy, t_ray ray, t_hit_record *rec);

t_cone		*cone(char **strs);
int			cone_hit(t_cone *cy, t_ray ray, t_hit_record *rec);


void	obj_set_rec(t_hit_record *rec);
void	obj_set_face_n(t_ray r, t_hit_record *rec);


//list
int			ft_lstsize(t_object *lst);
void		ft_lstadd_front(t_object **lst, t_object *new);
void		ft_lstadd_back(t_object **lst, t_object *new);
void		ft_lstdelone(t_object *lst, void (*del)(void *));
void		ft_lstclear(t_object **lst, void (*del)(void *));
void		ft_lstiter(t_object *lst, void (*f)(void *));
t_object	*ft_lstlast(t_object *lst);
t_object	*ft_lstmap(t_object *lst, void *(*f)(void *), void (*del)(void *));

t_object	*object(void *content, int type);

#endif