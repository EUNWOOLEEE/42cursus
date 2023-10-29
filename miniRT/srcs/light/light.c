/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:45:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/29 20:39:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_light			*light(char **strs);
t_color			light_phong(t_scene *scene, t_object *lights);
static t_color	get_point(t_scene *scene, t_light *light);

t_light	*light(char **strs)
{
	t_light	*light;
	double	ratio;

	ratio = 0.0;
	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_L);
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (!light)
		print_error_exit(MEMORY);
	if (parse_coor(&light->point, ft_split(strs[1], ',')) == FALSE \
		|| parse_double(&ratio, strs[2]) == FALSE \
		|| parse_color(&light->color, ft_split(strs[3], ',')) == FALSE \
		|| check_ratio(ratio) == FALSE
		|| check_color(light->color) == FALSE)
		print_error_exit(USAGE_L);
	light->color = color_to_albedo(light->color);
	light->color = vec_multi(light->color, ratio);
	return (light);
}

t_color	light_phong(t_scene *scene, t_object *lights)
{
	t_color		light_color;

	light_color = color(0, 0, 0); // 광원이 하나도 없을 경우 빛의 양
	while (lights)
	{
		if (lights->type == LIGHT)
			light_color = vec_plus2(light_color, get_point(scene, lights->obj));
		lights = lights->next;
	}
		
	light_color = vec_plus2(light_color, scene->ambient);
	light_color = vec_multi2(light_color, scene->rec.color);

	light_color.x = light_color.x >= 1 ? 1 : light_color.x;
	light_color.y = light_color.y >= 1 ? 1 : light_color.y;
	light_color.z = light_color.z >= 1 ? 1 : light_color.z;
	return(light_color);
}

static t_color	get_point(t_scene *scene, t_light *light)
{
	t_color	diffuse;
	t_vec	light_dir;
	double	light_len;
	t_ray	light_ray;
	double	theta;

	light_dir = vec_minus2(light->point, scene->rec.p);
	light_len = vec_len(light_dir);
	light_dir = vec_unit(light_dir);
	light_ray.orig = scene->rec.p;
	// light_ray.orig = vec_multi(scene->rec.p, EPSILON);
	light_ray.dir = vec_unit(vec_minus2(light->point, scene->rec.p));
	
	if (shadow(scene->world, light_ray, light_len))
		return (color(0, 0, 0));

	theta = vec_dot(scene->rec.n, light_dir);
	if (theta < 0.0)
		theta = 0.0;
	diffuse = vec_multi(light->color, theta);

	return (vec_plus2(diffuse, specular_get(scene, light, light_dir)));
}
