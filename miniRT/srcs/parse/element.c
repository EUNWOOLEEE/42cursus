/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:56:51 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/14 17:39:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	emt_A(t_element *A, char **strs)
{
	if (cnt_strs(strs) != 3)
		return (print_error_return(USAGE_A));
	A->light_ratio = ft_atod(strs[1]);
	set_rgb(&(A->rgb), ft_split(strs[2], ','));
	if (check_ratio(A->light_ratio) == FALSE ||
		check_rgb(A->rgb) == FALSE)
		return (print_error_return(USAGE_A));
	A->color = set_color(0, A->rgb.x, A->rgb.y, A->rgb.z);
	return (TRUE);
}

t_bool	emt_SR(t_element *SR, char **strs)
{
	if (cnt_strs(strs) != 3)
		return (print_error_return(USAGE_SR));
	SR->light_ratio = ft_atod(strs[1]);
	set_rgb(&(SR->rgb), ft_split(strs[2], ','));
	if (check_ratio(SR->light_ratio) == FALSE ||
		check_rgb(SR->rgb) == FALSE)
		return (print_error_return(USAGE_SR));
	SR->color = set_color(0, SR->rgb.x, SR->rgb.y, SR->rgb.z);
	return (TRUE);
}

t_bool	emt_C(t_element *C, char **strs)
{
	if (cnt_strs(strs) != 4)
		return (print_error_return(USAGE_C));
	set_coor(&(C->view_coor), ft_split(strs[1], ','));
	set_coor(&(C->vector_coor), ft_split(strs[2], ','));
	C->FOV = ft_atoi(strs[3]);
	if (check_vector(C->vector_coor) == FALSE ||
		check_FOV(C->FOV) == FALSE)
		return (print_error_return(USAGE_C));
	return (TRUE);
}

t_bool	emt_L(t_element *L, char **strs)
{
	if (cnt_strs(strs) != 4)
		return (print_error_return(USAGE_L));
	set_coor(&(L->light_coor), ft_split(strs[1], ','));
	L->light_ratio = ft_atod(strs[2]);
	set_rgb(&(L->rgb), ft_split(strs[3], ','));
	if (check_ratio(L->light_ratio) == FALSE ||
		check_rgb(L->rgb) == FALSE)
		return (print_error_return(USAGE_L));
	L->color = set_color(0, L->rgb.x, L->rgb.y, L->rgb.z);
	return (TRUE);
}
