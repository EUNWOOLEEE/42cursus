/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:47:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/25 10:13:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	hit(t_object *world, t_ray ray, t_hit_record *rec, t_bool light)
{
	t_bool	hit_anything;

	hit_anything = FALSE;
	if(light) debug = 1;
	while (world)
	{
		if (light == TRUE && hit_obj == world->num)
		{
			world = world->next;
			continue ;
		}
		// if (light) printf("hit %d now %d\n", hit_obj, world->num);
		if (hit_set_func(world, ray, rec))
		{
			hit_anything = TRUE;
			rec->t_max = rec->t;
			if (light == FALSE)
				hit_obj = world->num;
		}
		world = world->next;
	}
	debug = 0;
	return (hit_anything);
}

t_bool	hit_set_func(t_object *obj, t_ray ray, t_hit_record *rec)
{
	int	res;
	
	res = 0;
	if (obj->type == SP)
		res = sphere_hit((t_sphere *)obj->obj, ray, rec);
	else if (obj->type == PL)
		res = plane_hit((t_plane *)obj->obj, ray, rec);
	else if (obj->type == CY)
	{
		res += cylinder_hit_plane((t_cylinder *)obj->obj, ray, rec, TRUE);
		res += cylinder_hit_plane((t_cylinder *)obj->obj, ray, rec, FALSE);
		// res += cylinder_hit((t_cylinder *)obj->obj, ray, rec);
	}
	return res;
}
