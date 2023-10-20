/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:47:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 16:26:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	hit(t_scene *scene)
{
	t_bool	hit_anything;
	t_object	*world;

	world = scene->world;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_set_func(scene, world))
		{
			hit_anything = TRUE;
			scene->rec.t_max = scene->rec.t;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_set_func(t_scene *scene, t_object *obj)
{
	if (obj->type == SP)
		return (sphere_hit(scene, obj));
	return (FALSE);
}