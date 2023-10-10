/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:32:35 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/01 20:46:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	obj_sp(t_object *sp, char **strs)
{
	if (cnt_strs(strs) != 4)
		return (print_error_return(USAGE_SP));
	set_coor(&(sp->coor), ft_split(strs[1], ','));
	sp->diameter = ft_atod(strs[2]);
	set_rgb(&(sp->rgb), ft_split(strs[3], ','));
	if (check_rgb(sp->rgb) == FALSE)
		return (print_error_return(USAGE_SP));
	sp->color = set_color(0, sp->rgb.R, sp->rgb.G, sp->rgb.B);
	return (TRUE);
}

t_bool	obj_pl(t_object *pl, char **strs)
{
	if (cnt_strs(strs) != 4)
		return (print_error_return(USAGE_PL));
	set_coor(&(pl->coor), ft_split(strs[1], ','));
	set_coor(&(pl->vector_coor), ft_split(strs[2], ','));
	set_rgb(&(pl->rgb), ft_split(strs[3], ','));
	if (check_vector(pl->vector_coor) == FALSE ||
		check_rgb(pl->rgb) == FALSE)
		return (print_error_return(USAGE_PL));
	pl->color = set_color(0, pl->rgb.R, pl->rgb.G, pl->rgb.B);
	return (TRUE);
}

t_bool	obj_cy(t_object *cy, char **strs)
{
	if (cnt_strs(strs) != 6)
		return (print_error_return(USAGE_CY));
	set_coor(&(cy->coor), ft_split(strs[1], ','));
	set_coor(&(cy->vector_coor), ft_split(strs[2], ','));
	cy->diameter = ft_atod(strs[3]);
	cy->height = ft_atod(strs[4]);
	set_rgb(&(cy->rgb), ft_split(strs[5], ','));
	if (check_vector(cy->vector_coor) == FALSE ||
		check_rgb(cy->rgb) == FALSE)
		return (print_error_return(USAGE_CY));
	cy->color = set_color(0, cy->rgb.R, cy->rgb.G, cy->rgb.B);
	return (TRUE);
}

t_bool	obj_co(t_object *co, char **strs)
{
	if (cnt_strs(strs) != 6)
		return (print_error_return(USAGE_CO));
	set_coor(&(co->coor), ft_split(strs[1], ','));
	set_coor(&(co->vector_coor), ft_split(strs[2], ','));
	co->diameter = ft_atod(strs[3]);
	co->height = ft_atod(strs[4]);
	set_rgb(&(co->rgb), ft_split(strs[5], ','));
	if (check_vector(co->vector_coor) == FALSE ||
		check_rgb(co->rgb) == FALSE)
		return (print_error_return(USAGE_CO));
	co->color = set_color(0, co->rgb.R, co->rgb.G, co->rgb.B);
	return (TRUE);
}
