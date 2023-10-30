/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 13:25:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_sphere	*sphere(char **strs);
t_bool		sphere_hit(t_sphere *sp, t_ray ray, t_hit_record *rec);

t_sphere	*sphere(char **strs)
{
	t_sphere	*sp;

	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_SP);
	sp = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (!sp)
		print_error_exit(MEMORY);
	if (parse_coor(&(sp->center), ft_split(strs[1], ',')) == FALSE \
		|| parse_double(&sp->diameter, strs[2]) == FALSE \
		|| sp->diameter < 0 \
		|| parse_color(&(sp->color), ft_split(strs[3], ',')) == FALSE \
		|| check_color(sp->color) == FALSE)
		print_error_exit(USAGE_PL);
	sp->radius = sp->diameter / 2;
	sp->color = color_to_albedo(sp->color);
	return (sp);
}

t_bool	sphere_hit(t_sphere *sp, t_ray ray, t_hit_record *rec)
{
	t_discriminant	d;
	t_vec			cl;

	cl = vec_minus2(ray.orig, sp->center);
	d.a = vec_len_squared(ray.dir);
	d.half_b = vec_dot(ray.dir, cl);
	d.c = vec_len_squared(cl) - pow(sp->radius, 2);
	d.d = d.half_b * d.half_b - d.a * d.c;
	if (d.d < 0 \
		|| check_t_range(rec, &d) == FALSE)
		return (FALSE);
	rec->n = vec_divide(vec_minus2(ray_at(ray, d.t), sp->center), sp->radius);
	rec_set(ray, rec, d.t, sp->color);
	return (TRUE);
}
