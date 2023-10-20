/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:12:58 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/18 16:17:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_plane	*plane(char **strs)
{
	t_plane	*pl;

	if (cnt_strs(strs) != 4)
		print_error_exit(USAGE_PL);
	pl = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (!pl)
		print_error_exit(MEMORY);
	parse_coor(&(pl->coor), ft_split(strs[1], ','));
	parse_coor(&(pl->n), ft_split(strs[2], ','));
	parse_color(&(pl->color), ft_split(strs[3], ','));
	if (check_vector(pl->n) == FALSE ||
		check_color(pl->color) == FALSE)
		print_error_exit(USAGE_PL);
	return (pl);
}