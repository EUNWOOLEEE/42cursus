/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:31:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 15:21:48 by eunwolee         ###   ########.fr       */
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

//right, up만 구하는거
// void	cam_set(t_scene *scene)
// {
// 	double	theta;
// 	double	half_w;

// 	theta = cam_degrees_to_radians(scene->cam.FOV);
// 	half_w = tan(theta / 2);
// 	scene->cam.viewport_w = 2.0 * half_w;
// 	scene->cam.viewport_h = scene->cam.viewport_w / scene->img.aspect_ratio;

// 	if (vec_len(vec_cross(scene->cam.dir, vec(0, 1, 0))))
// 		scene->cam.vec_right = vec_unit(vec_cross(scene->cam.dir, vec(0, 1, 0)));
// 	else
// 		scene->cam.vec_right = vec_unit(vec_cross(scene->cam.dir, vec(0, 0, -1)));

// 	t_vec	tmp = vec_cross(scene->cam.dir, vec(0, 1, 0));
// 	printf("tmp %lf %lf %lf\n", tmp.x, tmp.y, tmp.z);

// 	printf("vec_right %lf %lf %lf\n", scene->cam.vec_right.x, scene->cam.vec_right.y, scene->cam.vec_right.z);
// 	scene->cam.vec_up = vec_unit(vec_cross(scene->cam.vec_right, scene->cam.dir));
// 	scene->cam.horizontal = vec_multi(scene->cam.vec_right, scene->cam.viewport_w);
// 	scene->cam.vertical = vec_multi(scene->cam.vec_up, scene->cam.viewport_h);
// 	printf("vec_up %lf %lf %lf\n", scene->cam.vec_up.x, scene->cam.vec_up.y, scene->cam.vec_up.z);
// 	printf("horizontal %lf %lf %lf\n", scene->cam.horizontal.x, scene->cam.horizontal.y, scene->cam.horizontal.z);
// 	printf("vertical %lf %lf %lf\n", scene->cam.vertical.x, scene->cam.vertical.y, scene->cam.vertical.z);

// 	scene->cam.llc = vec_plus2(scene->cam.orig, vec_multi(scene->cam.dir, scene->cam.focal_len));
// 	scene->cam.llc = vec_minus2(scene->cam.llc, vec_divide(scene->cam.horizontal, 2));
// 	scene->cam.llc = vec_minus2(scene->cam.llc, vec_divide(scene->cam.vertical, 2));
// }

//원래 쓰던거
// void	cam_set(t_scene *scene)
// {
// 	double	theta;
// 	double	half_w;

// 	theta = cam_degrees_to_radians(scene->cam.FOV);
// 	half_w = tan(theta / 2);
// 	scene->cam.viewport_w = 2.0 * half_w;
// 	scene->cam.viewport_h = scene->cam.viewport_w / scene->img.aspect_ratio;

// 	t_vec	lookat = vec(scene->cam.orig.x + scene->cam.dir.x, \
// 						scene->cam.orig.y + scene->cam.dir.y, \
// 						scene->cam.orig.z + scene->cam.dir.z - 1.0);
	
// 	printf("lookfrom %lf %lf %lf\n", scene->cam.orig.x, scene->cam.orig.y, scene->cam.orig.z);
// 	printf("lookat %lf %lf %lf\n", lookat.x, lookat.y, lookat.z);
// 	scene->cam.vec_up = vec(0, 1, 0);
// 	t_vec	tmp = vec_minus2(scene->cam.orig, lookat);
// 	t_vec	w;
// 	if (!tmp.x && !tmp.y && !tmp.z)
// 		w = vec(0, 0, 1);
// 	else
// 		w = vec_unit(vec_minus2(scene->cam.orig, lookat));
// 	t_vec	u = vec_unit(vec_cross(scene->cam.vec_up, w));
// 	t_vec	v = vec_cross(w, u);
// 	printf("w %lf %lf %lf\n", w.x, w.y, w.z);
// 	printf("u %lf %lf %lf\n", u.x, u.y, u.z);
// 	printf("v %lf %lf %lf\n", v.x, v.y, v.z);

// 	scene->cam.horizontal = vec_multi(u, scene->cam.viewport_w);
// 	scene->cam.vertical = vec_multi(v, scene->cam.viewport_h);
// 	printf("horizontal %lf %lf %lf\n", scene->cam.horizontal.x, scene->cam.horizontal.y, scene->cam.horizontal.z);
// 	printf("vertical %lf %lf %lf\n", scene->cam.vertical.x, scene->cam.vertical.y, scene->cam.vertical.z);

// 	scene->cam.llc = vec_minus2(scene->cam.orig, vec_divide(scene->cam.horizontal, 2));
// 	scene->cam.llc = vec_minus2(scene->cam.llc, vec_divide(scene->cam.vertical, 2));
// 	scene->cam.llc = vec_minus2(scene->cam.llc, w);
// }

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
	
	// t_vec	tmp = vec_minus2(scene->cam.orig, lookat);
	// printf("tmp %lf %lf %lf\n", tmp.x, tmp.y, tmp.z);

	t_vec	u = vec_unit(vec_cross(scene->cam.vec_up, w));
	t_vec	v = vec_cross(w, u);
	// printf("w %lf %lf %lf\n", w.x, w.y, w.z);
	// printf("u %lf %lf %lf\n", u.x, u.y, u.z);
	// printf("v %lf %lf %lf\n", v.x, v.y, v.z);

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