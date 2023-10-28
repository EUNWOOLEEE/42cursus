/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:30:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 20:16:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void			specular(t_scene *scene, char **strs);
t_color			specular_get(t_scene *scene, t_light *light, t_vec light_dir);
static t_vec	reflect(t_vec v, t_vec n);

void	specular(t_scene *scene, char **strs)
{
	if (cnt_strs(strs) != 2)
		print_error_exit(USAGE_SR);
	if (parse_double(&scene->specular_ratio, strs[1]) == FALSE \
		|| check_ratio(scene->specular_ratio) == FALSE)
		print_error_exit(USAGE_SR);
}

t_color	specular_get(t_scene *scene, t_light *light, t_vec light_dir)
{
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	spec;

	view_dir = vec_unit(vec_multi(scene->ray.dir, -1));
	reflect_dir = reflect(light_dir, scene->rec.n);
	double	shininess = 256; //값이 커질수록 하이라이팅 범위가 좁아짐, 더 반짝거리는 물체, 오브젝트 각각에 넣어주기
	spec = vec_dot(view_dir, reflect_dir);
	if (spec < 0)
		spec = 0.0;
	spec = pow(spec, shininess);
	return (vec_multi(vec_multi(light->color, scene->specular_ratio), spec));
}

static t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_plus2(vec_multi(v, -1), vec_multi(n, vec_dot(v, n) * 2)));
}
