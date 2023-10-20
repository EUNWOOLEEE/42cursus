/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:45:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 16:32:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_light	*light(char **strs)
{
	t_light	*light;

	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_L);
	light = (t_light *)ft_calloc(1, sizeof(t_light));
	if (!light)
		print_error_exit(MEMORY);
	parse_coor(&light->point, ft_split(strs[1], ','));
	light->ratio = ft_atod(strs[2]);
	parse_color(&light->color, ft_split(strs[3], ','));
	if (check_ratio(light->ratio) == FALSE ||
		check_color(light->color) == FALSE)
		print_error_exit(USAGE_L);
	return light;
}

t_color	light_phong(t_scene *scene)
{
	t_color		l_color;
	t_object	*lights;

	l_color = color(0, 0, 0); // 광원이 하나도 없을 경우 빛의 양
	lights = scene->light;
	(void)lights;
	// while (lights)
	// {
	// 	if (lights->type == LIGHT_POINT)
	// 		l_color = vec_plus2(l_color, light_get_point(scene, lights->obj));
	// 	lights = lights->next;
	// }
	l_color = vec_plus2(l_color, scene->amb);
	l_color = vec_multi2(l_color, scene->rec.albedo);
	if (l_color.x == 1 && l_color.y == 1 && l_color.z == 1)
		return (color(1, 1, 1));
	return(l_color);
}