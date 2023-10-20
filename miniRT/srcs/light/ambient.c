/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:42:26 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 16:13:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	amb(t_scene *scene, char **strs)
{
	double	ratio;
	t_color	color;

	if (cnt_strs(strs) != 3)
		print_error_exit(USAGE_A);
	ratio = ft_atod(strs[1]);
	parse_color(&(color), ft_split(strs[2], ','));
	if (check_ratio(ratio) == FALSE ||
		check_color(color) == FALSE)
		print_error_exit(USAGE_A);
	scene->amb = vec_multi(color, ratio);
}