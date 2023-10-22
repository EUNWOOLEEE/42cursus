/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:31:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/21 16:13:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

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

	t_vec	lookat = vec(scene->cam.orig.x + scene->cam.dir.x, \
						scene->cam.orig.y + scene->cam.dir.y, \
						scene->cam.orig.z + scene->cam.dir.z - 1.0);
	
	// printf("lookfrom %lf %lf %lf\n", scene->cam.orig.x, scene->cam.orig.y, scene->cam.orig.z);
	// printf("lookat %lf %lf %lf\n", lookat.x, lookat.y, lookat.z);
	scene->cam.vec_up = vec(0, 1, 0);
	t_vec	w;
	if (!vec_len(vec_unit(vec_minus2(scene->cam.orig, lookat))))
		w = vec(0, 0, -1);
	else
		w = vec_unit(vec_minus2(scene->cam.orig, lookat));
	
	t_vec	u = vec_unit(vec_cross(scene->cam.vec_up, w));
	t_vec	v = vec_cross(w, u);

	scene->cam.horizontal = vec_multi(u, scene->cam.viewport_w);
	scene->cam.vertical = vec_multi(v, scene->cam.viewport_h);
	// printf("horizontal %lf %lf %lf\n", scene->cam.horizontal.x, scene->cam.horizontal.y, scene->cam.horizontal.z);
	// printf("vertical %lf %lf %lf\n", scene->cam.vertical.x, scene->cam.vertical.y, scene->cam.vertical.z);

	scene->cam.llc = vec_minus2(scene->cam.orig, vec_divide(scene->cam.horizontal, 2));
	scene->cam.llc = vec_minus2(scene->cam.llc, vec_divide(scene->cam.vertical, 2));
	scene->cam.llc = vec_minus2(scene->cam.llc, w);
}

static double	cam_degrees_to_radians(int degrees)
{
	return (degrees * pi / 180.0);
}