/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:31:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 14:22:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void			cam(t_scene *scene, char **strs);
void			cam_set(t_scene *scene);
static double	cam_degrees_to_radians(int degrees);

void	cam(t_scene *scene, char **strs)
{
	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_C);
	parse_coor(&(scene->cam.orig), ft_split(strs[1], ','));
	parse_coor(&(scene->cam.dir), ft_split(strs[2], ','));
	scene->cam.FOV = ft_atoi(strs[3]);
	if (check_vector(scene->cam.dir) == FALSE ||
		check_FOV(scene->cam.FOV) == FALSE)
		print_error_exit(USAGE_C);
}

void	cam_set(t_scene *scene)
{
	double	theta;
	double	half_w;

	theta = cam_degrees_to_radians(scene->cam.FOV);
	half_w = tan(theta / 2);
	scene->cam.viewport_w = 2.0 * half_w;
	scene->cam.viewport_h = scene->cam.viewport_w / scene->img.aspect_ratio;
	
	scene->cam.vec_up = vec(0, 1, 0);
	
	t_vec	w = vec_unit(vec_multi(scene->cam.dir, -1));
	t_vec	u = vec_cross(scene->cam.vec_up, w);
	if (!vec_len(u))
		u = vec_unit(vec_cross(vec(0, 0, -1), w));
	else
		u = vec_unit(u);
	t_vec	v = vec_cross(w, u);

	scene->cam.horizontal = vec_multi(u, scene->cam.viewport_w);
	scene->cam.vertical = vec_multi(v, scene->cam.viewport_h);

	scene->cam.llc = vec_minus2(scene->cam.orig, vec_divide(scene->cam.horizontal, 2));
	scene->cam.llc = vec_minus2(scene->cam.llc, vec_divide(scene->cam.vertical, 2));
	scene->cam.llc = vec_minus2(scene->cam.llc, w);
}

static double	cam_degrees_to_radians(int degrees)
{
	return (degrees * pi / 180.0);
}