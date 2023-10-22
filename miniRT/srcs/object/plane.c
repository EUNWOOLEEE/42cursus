/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:12:58 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/22 19:47:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_plane	*plane(char **strs)
{
	t_plane	*pl;

	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_PL);
	pl = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (!pl)
		print_error_exit(MEMORY);
	parse_coor(&(pl->center), ft_split(strs[1], ','));
	parse_coor(&(pl->dir), ft_split(strs[2], ','));
	parse_color(&(pl->color), ft_split(strs[3], ','));
	if (check_vector(pl->dir) == FALSE ||
		check_color(pl->color) == FALSE)
		print_error_exit(USAGE_PL);
	pl->color = color_to_albedo(pl->color);
	return (pl);
}

// t_bool	plane_hit(t_plane *pl, t_ray ray, t_hit_record *rec)
// {
// 	double	dot;
// 	double	t;

// 	dot = vec_dot(ray.dir, pl->dir);
// 	if (fabs(dot) < EPSILON)
// 		return (FALSE);
// 	t = vec_dot(vec_minus2(pl->center, ray.orig), pl->dir) / dot;
// 	if (t < rec->t_min || rec->t_max < t)
// 		return (FALSE);
// 	rec->t = t;
// 	rec->p = ray_at(ray, t);
// 	rec->n = pl->dir;
// 	// obj_set_face_n(ray, rec);
// 	rec->color = pl->color;
// 	return (TRUE);
// }

t_bool	plane_hit(t_plane *pl, t_ray ray, t_hit_record *rec)
{
	double	dot;
	double	t;

	dot = vec_dot(ray.dir, pl->dir);
	if (fabs(dot) < EPSILON)
		return (FALSE);
	t = vec_dot(vec_minus2(pl->center, ray.orig), pl->dir) / dot;
	if(debug && ray.orig.x != 0 && ray.orig.y != 0 && ray.orig.z != 5)
	{
		printf("light orig %lf %lf %lf\n", ray.orig.x, ray.orig.y, ray.orig.z);
		printf("light dir %lf %lf %lf\n", ray.dir.x, ray.dir.y, ray.dir.z);
		printf("dot: %lf t: %lf\n", dot, t);
		printf("t_min: %lf t: %lf t_max: %lf\n", rec->t_min, t, rec->t_max);
		if (t < rec->t_min || rec->t_max < t)
			printf("not hit\n\n");
		debug = 0;
	}
	if (t < rec->t_min || rec->t_max < t)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->n = pl->dir;
	// obj_set_face_n(ray, rec);
	rec->color = pl->color;
	return (TRUE);
}