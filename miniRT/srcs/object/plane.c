/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:12:58 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 16:31:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_plane	*plane(char **strs);
t_bool	plane_hit(t_plane *pl, t_ray ray, t_hit_record *rec);

t_plane	*plane(char **strs)
{
	t_plane	*pl;

	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_PL);
	pl = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (!pl)
		print_error_exit(MEMORY);
	if (parse_coor(&(pl->center), ft_split(strs[1], ',')) == FALSE \
		|| parse_coor(&(pl->dir), ft_split(strs[2], ',')) == FALSE \
		|| parse_color(&(pl->color), ft_split(strs[3], ',')) == FALSE \
		|| check_vector(pl->dir) == FALSE \
		|| check_color(pl->color) == FALSE)
		print_error_exit(USAGE_PL);
	pl->color = color_to_albedo(pl->color);
	pl->dir = vec_unit(pl->dir);
	return (pl);
}

t_bool	plane_hit(t_plane *pl, t_ray ray, t_hit_record *rec)
{
	double	dot;
	double	t;

	dot = vec_dot(ray.dir, pl->dir);
	if (fabs(dot) < EPSILON)
		return (FALSE);
	t = vec_dot(vec_minus2(pl->center, ray.orig), pl->dir) / dot;
	if (t < rec->t_min || rec->t_max < t)
		return (FALSE);
	rec->n = vec_unit(pl->dir);
	rec_set(ray, rec, t, pl->color);
	return (TRUE);
}