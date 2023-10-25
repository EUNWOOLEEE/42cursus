/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/25 10:39:32 by eunwolee         ###   ########.fr       */
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
	sp->color = color_to_albedo(sp->color);
	return (sp);
}

t_bool	sphere_hit(t_sphere *sp, t_ray ray, t_hit_record *rec)
{
	t_vec		cl;
	double		a;
	double		half_b;
	double		c;
	double		D;

	cl = vec_minus2(ray.orig, sp->center);
	a = vec_len_squared(ray.dir);
	half_b = vec_dot(ray.dir, cl);
	c = vec_len_squared(cl) - pow(sp->radius, 2);

	D = half_b * half_b - a * c;
	if (D < 0)
		return (FALSE);

	double	t = (-half_b - sqrt(D)) / a;
	
	if (t < rec->t_min || rec->t_max < t)
	{
		t = (-half_b + sqrt(D)) / a;
		if (t < rec->t_min || rec->t_max < t)
			return (FALSE);
	}
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->n = vec_divide(vec_minus2(rec->p, sp->center), sp->radius);
	obj_set_face_n(ray, rec);
	rec->color = sp->color;
	return (TRUE);
}