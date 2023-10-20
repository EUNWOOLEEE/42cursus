/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:17:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/16 14:48:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	parse_func(t_scene *scene, char **strs)
{
	if (!ft_strncmp(strs[0], "A", 2))
		amb(scene, strs);
	else if(!ft_strncmp(strs[0], "C", 2))
		cam(scene, strs);
	else if(!ft_strncmp(strs[0], "L", 2))
		ft_lstadd_back(&scene->world, object(light(strs), L));
	else if(!ft_strncmp(strs[0], "sp", 3))
		ft_lstadd_back(&scene->world, object(sphere(strs), SP));
	else if(!ft_strncmp(strs[0], "pl", 3))
		ft_lstadd_back(&scene->world, object(plane(strs), PL));
	else if(!ft_strncmp(strs[0], "cy", 3))
		ft_lstadd_back(&scene->world, object(cylinder(strs), CY));
	// else if(!ft_strncmp(strs[0], "co", 3))
		// new = object(cone(strs), co);
	else if (ft_strncmp(strs[0], "co", 3))
		print_error_exit("Contain not allowed type\n");
		//파싱 된 것들만 가지고 동작할 수 있게 수정하기
}

t_bool	parse_color(t_color *rgb, char **strs)
{
	if (!strs)
		return (FALSE);
	if (cnt_strs(strs) != 3)
		return (FALSE);
	rgb->x = (long long)ft_atoi(strs[0]);
	rgb->y = (long long)ft_atoi(strs[1]);
	rgb->z = (long long)ft_atoi(strs[2]);
	return (TRUE);
}

t_bool	parse_coor(t_vec *coor, char **strs)
{
	if (!strs)
		return (FALSE);
	if (cnt_strs(strs) != 3)
		return (FALSE);
	coor->x = ft_atod(strs[0]);
	coor->y = ft_atod(strs[1]);
	coor->z = ft_atod(strs[2]);
	return (TRUE);
}
