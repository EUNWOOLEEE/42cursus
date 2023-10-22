/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:47:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/22 19:51:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	hit(t_object *world, t_ray ray, t_hit_record *rec)
{
	t_bool	hit_anything;

	hit_anything = FALSE;
	while (world)
	{
		if (hit_set_func(world, ray, rec))
		{
			hit_anything = TRUE;
			rec->t_max = rec->t;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_set_func(t_object *obj, t_ray ray, t_hit_record *rec)
{
	int res = 0;
	if (obj->type == SP)
	{
		res = sphere_hit((t_sphere *)obj->obj, ray, rec);
		if (debug) printf("sp %d\n", res);
	}
	else if (obj->type == PL)
	{
		res = plane_hit((t_plane *)obj->obj, ray, rec);
		if (debug) printf("pl %d\n", res);
	}
	return res;
}