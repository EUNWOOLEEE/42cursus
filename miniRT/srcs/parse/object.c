/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:32:35 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 17:18:02 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	obj_sp(t_object *sp, char **strs)
{
	if (cnt_strs(strs) != 4)
	{
		printf("Usage: sp | x,y,z coordinates of the sphere center | the sphere diameter | R,G,B colors in range [0-255]\n");
		return (FALSE);
	}
	set_coor(&(sp->coor), ft_split(strs[1], ','));
	sp->diameter = ft_atod(strs[2]);
	set_color(&(sp->color), ft_split(strs[3], ','));
	return (TRUE);
}

t_bool	obj_pl(t_object *pl, char **strs)
{
	if (cnt_strs(strs) != 4)
	{
		printf("pl | x,y,z coordinates of a point in the plane | 3d normalized normal vector. In range [-1,1] for each x,y,z axis | R,G,B colors in range [0-255]\n");
		return (FALSE);
	}
	set_coor(&(pl->coor), ft_split(strs[1], ','));
	set_coor(&(pl->vector_coor), ft_split(strs[2], ','));
	set_color(&(pl->color), ft_split(strs[3], ','));
	return (TRUE);
}

t_bool	obj_cy(t_object *cy, char **strs)
{
	if (cnt_strs(strs) != 6)
	{
		printf("cy | x,y,z coordinates of the center of the cylinder | 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis | the cylinder diameter | the cylinder height | R,G,B colors in range [0,255]\n");
		return (FALSE);
	}
	set_coor(&(cy->coor), ft_split(strs[1], ','));
	set_coor(&(cy->vector_coor), ft_split(strs[2], ','));
	cy->diameter = ft_atod(strs[3]);
	cy->height = ft_atod(strs[4]);
	set_color(&(cy->color), ft_split(strs[5], ','));
	return (TRUE);
}

t_bool	obj_co(t_object *co, char **strs)
{
	if (cnt_strs(strs) != 6)
	{
		printf("cy | 임시\n");
		return (FALSE);
	}
	set_coor(&(co->coor), ft_split(strs[1], ','));
	set_coor(&(co->vector_coor), ft_split(strs[2], ','));
	co->diameter = ft_atod(strs[3]);
	co->height = ft_atod(strs[4]);
	set_color(&(co->color), ft_split(strs[5], ','));
	return (TRUE);
}
