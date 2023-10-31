/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:45:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/31 15:45:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void			light(t_scene *scene, char **strs);
t_color			light_phong(t_scene *scene);
static t_color	get_point(t_scene *scene);
static t_color	check_max(t_color light_color);

void	light(t_scene *scene, char **strs)
{
	double	ratio;

	ratio = 0.0;
	if (cnt_strs(strs) != 4 || scene->light.check_light == TRUE)
		print_error_exit(USAGE_L);
	if (parse_coor(&scene->light.point, ft_split(strs[1], ',')) == FALSE \
		|| parse_double(&ratio, strs[2]) == FALSE \
		|| parse_color(&scene->light.color, ft_split(strs[3], ',')) == FALSE \
		|| check_ratio(ratio) == FALSE
		|| check_color(scene->light.color) == FALSE)
		print_error_exit(USAGE_L);
	scene->light.color = color_to_albedo(scene->light.color);
	scene->light.color = vec_multi(scene->light.color, ratio);
	scene->light.check_light = TRUE;
}

t_color	light_phong(t_scene *scene)
{
	t_color		light_color;

	light_color = get_point(scene);
	light_color = vec_plus2(light_color, scene->light.ambient);
	light_color = vec_multi2(light_color, scene->rec.color);
	return (check_max(light_color));
}

static t_color	get_point(t_scene *scene)
{
	t_color	diffuse;
	t_vec	light_dir;
	double	light_len;
	t_ray	light_ray;
	double	theta;

	light_dir = vec_minus2(scene->light.point, scene->rec.p);
	light_len = vec_len(light_dir);
	light_dir = vec_unit(light_dir);
	light_ray.orig = scene->rec.p;
	light_ray.dir = vec_unit(vec_minus2(scene->light.point, scene->rec.p));
	if (shadow(scene->world, light_ray, light_len))
		return (color(0, 0, 0));
	theta = vec_dot(scene->rec.n, light_dir);
	if (theta < 0.0)
		theta = 0.0;
	diffuse = vec_multi(scene->light.color, theta);
	return (diffuse);
}

static t_color	check_max(t_color light_color)
{
	if (light_color.x > 1)
		light_color.x = 1;
	if (light_color.y > 1)
		light_color.y = 1;
	if (light_color.z > 1)
		light_color.z = 1;
	return (light_color);
}
