/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:56:51 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/28 14:20:34 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	emt_A(t_element *A, char **strs)
{
	if (cnt_strs(strs) != 3)
	{
		printf("Usage: A | ambient lighting ratio in range [0.0,1.0] | R,G,B [0-255]\n");
		return (FALSE);
	}
	A->light_ratio = ft_atod(strs[1]);
	set_color(&(A->color), ft_split(strs[2], ','));
	if (check_ratio(A->light_ratio) == FALSE ||
		check_color(A->color) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	emt_SR(t_element *SR, char **strs)
{
	if (cnt_strs(strs) != 3)
	{
		printf("Usage: SR | 임시\n");
		return (FALSE);
	}
	SR->light_ratio = ft_atod(strs[1]);
	set_color(&(SR->color), ft_split(strs[2], ','));
	if (check_ratio(SR->light_ratio) == FALSE ||
		check_color(SR->color) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	emt_C(t_element *C, char **strs)
{
	if (cnt_strs(strs) != 4)
	{
		printf("Usage: C | x,y,z coordinates of the view point | 3d normalized orientation vector. In range [-1,1] for each x,y,z axis | FOV : Horizontal field of view in degrees in range [0,180]\n");
		return (FALSE);
	}
	set_coor(&(C->view_coor), ft_split(strs[1], ','));
	set_coor(&(C->vector_coor), ft_split(strs[2], ','));
	C->FOV = ft_atoi(strs[3]);
	if (check_vector(C->vector_coor) == FALSE ||
		check_FOV(C->FOV) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	emt_L(t_element *L, char **strs)
{
	if (cnt_strs(strs) != 4)
	{
		printf("Usage: L | x,y,z coordinates of the light point | the light brightness ratio in range | R,G,B colors in range [0-255]\n");
		return (FALSE);
	}
	set_coor(&(L->light_coor), ft_split(strs[1], ','));
	L->light_ratio = ft_atod(strs[2]);
	set_color(&(L->color), ft_split(strs[3], ','));
	if (check_ratio(L->light_ratio) == FALSE ||
		check_color(L->color) == FALSE)
		return (FALSE);
	return (TRUE);
}
