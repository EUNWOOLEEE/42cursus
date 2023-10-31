/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:42:26 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/31 15:43:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ambient(t_scene *scene, char **strs)
{
	double	ratio;

	ratio = 0.0;
	if (cnt_strs(strs) != 3 || scene->light.check_ambient == TRUE)
		print_error_exit(USAGE_A);
	if (parse_double(&ratio, strs[1]) == FALSE \
		|| parse_color(&scene->light.ambient, \
						ft_split(strs[2], ',')) == FALSE \
		|| check_ratio(ratio) == FALSE \
		|| check_color(scene->light.ambient) == FALSE)
		print_error_exit(USAGE_A);
	scene->light.ambient = color_to_albedo(scene->light.ambient);
	scene->light.ambient = vec_multi(scene->light.ambient, ratio);
	scene->light.check_ambient = TRUE;
}
