/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:26:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/23 06:47:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_point	ray_at(t_ray ray, double t)
{
	t_point	at;

	at = vec_plus2(ray.orig, vec_multi(ray.dir, t));
	return (at);
}

t_ray	ray_first(t_scene *scene, double u, double v)
{
	t_ray	r;

	r.orig = scene->cam.orig;
	r.dir = vec_plus2(scene->cam.llc, vec_multi(scene->cam.horizontal, u));
	r.dir = vec_plus2(r.dir, vec_multi(scene->cam.vertical, v));
	r.dir = vec_minus2(r.dir, r.orig);
	return (r);
}

t_color	ray_color(t_scene *scene)
{
	double			t;

	obj_set_rec(&scene->rec);
	if (hit(scene->world, scene->ray, &scene->rec, FALSE))
		return (light_phong(scene, scene->light));
	// return (color(0, 0, 0));
	t = 0.5 * (scene->ray.dir.y + 1.0);
	return (vec_plus2(vec_multi(color(1.0, 1.0, 1.0), 1.0 - t), \
			vec_multi(color(0.5, 0.7, 1.0), t)));
}