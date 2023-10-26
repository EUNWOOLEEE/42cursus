/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:45:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/26 15:32:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

static t_color	get_point(t_scene *scene, t_light *light);
static t_vec	reflect(t_vec v, t_vec n);

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
		|| parse_ratio(&ratio, strs[2]) == FALSE \
		|| parse_color(&light->color, ft_split(strs[3], ',')) == FALSE \
		|| check_ratio(ratio) == FALSE
		|| check_color(light->color) == FALSE)
		print_error_exit(USAGE_L);
	light->color = color_to_albedo(light->color);
	light->color = vec_multi(light->color, ratio);
	return (light);
}

void	specular(t_scene *scene, char **strs)
{
	if (cnt_strs(strs) != 2)
		print_error_exit(USAGE_SR);
	scene->specular_ratio = ft_atod(strs[1]);
	if (check_ratio(scene->specular_ratio) == FALSE)
		print_error_exit(USAGE_SR);
}

t_color	light_phong(t_scene *scene, t_object *lights)
{
	t_color		light_color;

	light_color = color(0, 0, 0); // 광원이 하나도 없을 경우 빛의 양
	// int i = 0;
	// if(i)
	// 	get_point(scene, lights->obj);
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vec_plus2(light_color, get_point(scene, lights->obj));
		lights = lights->next;
	}
		
	light_color = vec_plus2(light_color, scene->ambient);
	light_color = vec_multi2(light_color, scene->rec.color);

	light_color.x = light_color.x >= 1 ? 1 : light_color.x;
	light_color.y = light_color.y >= 1 ? 1 : light_color.y;
	light_color.z = light_color.z >= 1 ? 1 : light_color.z;
	// printf("%lf %lf %lf\n\n", light_color.x, light_color.y, light_color.z);
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
	// light_ray.dir = vec_plus2(scene->rec.p, vec_multi(scene->rec.n, EPSILON)); // hit point->광원의 원점
	light_ray.dir = vec_unit(vec_minus2(light->point, scene->rec.p));
	
	// printf("light_ray orig %lf %lf %lf\n", light_ray.orig.x, light_ray.orig.y, light_ray.orig.z);
	// printf("light_ray dir %lf %lf %lf\n", light_ray.dir.x, light_ray.dir.y, light_ray.dir.z);
	
	if (shadow(scene->world, light_ray, light_len))
		return (color(0, 0, 0));

	theta = vec_dot(scene->rec.n, light_dir);
	if (theta < 0.0)
		theta = 0.0;
	diffuse = vec_multi(light->color, theta);

	t_vec	view_dir;
	t_vec	reflect_dir;

	//sr이 있는지 확인하는거 넣기
	view_dir = vec_unit(vec_multi(scene->ray.dir, -1));
	reflect_dir = reflect(light_dir, scene->rec.n);
	double	shininess = 64; //값이 커질수록 하이라이팅 범위가 좁아짐, 더 반짝거리는 물체, 오브젝트 각각에 넣어주기
	double	spec = vec_dot(view_dir, reflect_dir);
	if (spec < 0)
		spec = 0.0;
	spec = pow(spec, shininess);
	t_color	specular_ = vec_multi(vec_multi(light->color, scene->specular_ratio), spec);
	return (vec_plus2(diffuse, specular_));
}

static t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_plus2(vec_multi(v, -1), vec_multi(n, vec_dot(v, n) * 2)));
}