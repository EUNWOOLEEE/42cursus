/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 16:25:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_sphere	*sphere(char **strs)
{
	t_sphere	*sp;
	
	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_SP);
	sp = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (!sp)
		print_error_exit(MEMORY);
	parse_coor(&(sp->center), ft_split(strs[1], ','));
	sp->diameter = ft_atod(strs[2]);
	sp->radius = sp->diameter / 2;
	sp->radius_squared = sp->radius * sp->radius;
	parse_color(&(sp->color), ft_split(strs[3], ','));
	if (check_color(sp->color) == FALSE)
		print_error_exit(USAGE_PL);
	return (sp);
}

t_bool	sphere_hit(t_scene *scene, t_object *obj)
{
	t_sphere	*sp;
	t_vec		oc;
	double		a;
	double		half_b;
	double		c;
	double		D;

	sp = (t_sphere *)obj->obj;
	oc = vec_minus2(scene->ray.orig, sp->center);
	a = vec_len_squared(scene->ray.dir);
	half_b = vec_dot(scene->ray.dir, oc);
	c = vec_len_squared(oc) - sp->radius * sp->radius;
	
	D = half_b * half_b - a * c;
	if (D < 0)
		return (FALSE);

	double	sqrtd = sqrt(D);
	double	root = (-half_b - sqrtd) / a;
	if (root < scene->rec.t_min || scene->rec.t_max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < scene->rec.t_min || scene->rec.t_max < root)
			return (FALSE);
	}

	scene->rec.t = root;
	scene->rec.p = ray_at(scene->ray, root);
	scene->rec.n = vec_divide(vec_minus2(scene->rec.p, sp->center), sp->radius);
	obj_set_face_n(scene->ray, &scene->rec);
	scene->rec.albedo = obj->albedo;
	return (TRUE);
}