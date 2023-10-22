/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:42:26 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 20:34:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ambient(t_scene *scene, char **strs)
{
	double	ratio;

	if (cnt_strs(strs) != 3)
		print_error_exit(USAGE_A);
	ratio = ft_atod(strs[1]);
	parse_color(&(scene->ambient), ft_split(strs[2], ','));
	if (check_ratio(ratio) == FALSE ||
		check_color(scene->ambient) == FALSE)
		print_error_exit(USAGE_A);
	scene->ambient = color_to_albedo(scene->ambient);
	scene->ambient = vec_multi(scene->ambient, ratio);
}