/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:31:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 13:56:56 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void			cam(t_scene *scene, char **strs);
void			cam_set(t_scene *scene);
static void		set_lower_left_corner(t_scene *scene, t_vec w);
static double	degrees_to_radians(int degrees);

void	cam(t_scene *scene, char **strs)
{
	int	i;

	if (cnt_strs(strs) != 4 || scene->cam.check_cam == TRUE)
		print_error_exit(USAGE_C);
	i = -1;
	while (strs[3][++i])
		if (!ft_isdigit(strs[3][i]) && strs[3][i] != '\n')
			print_error_exit(USAGE_C);
	scene->cam.fov = ft_atoi(strs[3]);
	if (parse_coor(&scene->cam.orig, ft_split(strs[1], ',')) == FALSE \
		|| parse_coor(&scene->cam.dir, ft_split(strs[2], ',')) == FALSE \
		|| check_vector(scene->cam.dir) == FALSE \
		|| check_fov(scene->cam.fov) == FALSE)
		print_error_exit(USAGE_C);
	scene->cam.check_cam = TRUE;
}

void	cam_set(t_scene *scene)
{
	double	theta;
	double	half_w;
	t_vec	w;
	t_vec	u;
	t_vec	v;

	theta = degrees_to_radians(scene->cam.fov);
	half_w = tan(theta / 2);
	scene->cam.viewport_w = 2.0 * half_w;
	scene->cam.viewport_h = scene->cam.viewport_w / scene->img.aspect_ratio;
	w = vec_unit(vec_multi(scene->cam.dir, -1));
	u = vec_cross(vec(0, 1, 0), w);
	if (!vec_len(u))
		u = vec_unit(vec_cross(vec(0, 0, -1), w));
	else
		u = vec_unit(u);
	v = vec_cross(w, u);
	scene->cam.horizontal = vec_multi(u, scene->cam.viewport_w);
	scene->cam.vertical = vec_multi(v, scene->cam.viewport_h);
	set_lower_left_corner(scene, w);
}

static void	set_lower_left_corner(t_scene *scene, t_vec w)
{
	scene->cam.llc = vec_minus2(scene->cam.orig, \
						vec_divide(scene->cam.horizontal, 2));
	scene->cam.llc = vec_minus2(scene->cam.llc, \
						vec_divide(scene->cam.vertical, 2));
	scene->cam.llc = vec_minus2(scene->cam.llc, w);
}

static double	degrees_to_radians(int degrees)
{
	return (degrees * PI / 180.0);
}
