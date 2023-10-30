/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:30:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 08:11:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void			specular(t_scene *scene, char **strs);
t_color			specular_get(t_scene *scene, t_light *light, t_vec light_dir);
static t_vec	reflect(t_vec v, t_vec n);

void	specular(t_scene *scene, char **strs)
{
	if (cnt_strs(strs) != 2 || scene->light_com.check_specular == TRUE)
		print_error_exit(USAGE_SR);
	if (parse_double(&scene->light_com.specular_ratio, strs[1]) == FALSE \
		|| check_ratio(scene->light_com.specular_ratio) == FALSE)
		print_error_exit(USAGE_SR);
	scene->light_com.check_specular = TRUE;
}

t_color	specular_get(t_scene *scene, t_light *light, t_vec light_dir)
{
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	spec;
	double	shininess;

	view_dir = vec_unit(vec_multi(scene->ray.dir, -1));
	reflect_dir = reflect(light_dir, scene->rec.n);
	shininess = 128;
	spec = vec_dot(view_dir, reflect_dir);
	if (spec < 0)
		spec = 0.0;
	spec = pow(spec, shininess);
	return (vec_multi(vec_multi(light->color, scene->light_com.specular_ratio), spec));
}

static t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_plus2(vec_multi(v, -1), vec_multi(n, vec_dot(v, n) * 2)));
}
