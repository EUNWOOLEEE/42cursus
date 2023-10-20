/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:16:17 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/18 18:42:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_cylinder	*cylinder(char **strs)
{
	t_cylinder	*cy;
	
	if (cnt_strs(strs) != 6)
		print_error_exit(USAGE_CY);
	cy = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		print_error_exit(MEMORY);
	parse_coor(&(cy->center), ft_split(strs[1], ','));
	parse_coor(&(cy->n), ft_split(strs[2], ','));
	cy->diameter = ft_atod(strs[3]);
	cy->h = ft_atod(strs[4]);
	parse_color(&(cy->color), ft_split(strs[5], ','));
	if (check_vector(cy->n) == FALSE ||
		check_color(cy->color) == FALSE)
		print_error_exit(USAGE_CY);
	return (cy);
}