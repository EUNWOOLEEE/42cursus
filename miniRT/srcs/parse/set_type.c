/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:17:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/28 14:17:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	set_func(t_info *info, char **strs)
{
	t_bool	res;

	res = TRUE;
	if (!ft_strncmp(strs[0], "A", 2))
		res = emt_A(&(info->A), strs);
	else if(!ft_strncmp(strs[0], "SR", 2))
		res = emt_SR(&(info->SR), strs);
	else if(!ft_strncmp(strs[0], "C", 2))
		res = emt_C(&(info->C), strs);
	else if(!ft_strncmp(strs[0], "L", 2))
		res = emt_L(&(info->L), strs);
	else if(!ft_strncmp(strs[0], "sp", 3))
		res = obj_sp(&(info->sp), strs);
	else if(!ft_strncmp(strs[0], "pl", 3))
		res = obj_pl(&(info->pl), strs);
	else if(!ft_strncmp(strs[0], "cy", 3))
		res = obj_cy(&(info->cy), strs);
	else if(!ft_strncmp(strs[0], "co", 3))
		res = obj_co(&(info->co), strs);
	else
		res = FALSE;
	return (res);
}

t_bool	set_color(t_color *color, char **strs)
{
	if (!strs)
		return (FALSE);
	if (cnt_strs(strs) != 3)
	{
		printf("Usage: R,G,B [0-255]\n");
		return (FALSE);
	}
	color->R = ft_atoi(strs[0]);
	color->G = ft_atoi(strs[1]);
	color->B = ft_atoi(strs[2]);
	return (TRUE);
}

t_bool	set_coor(t_coor *coor, char **strs)
{
	if (!strs)
		return (FALSE);
	if (cnt_strs(strs) != 3)
	{
		printf("Usage: x,y,z (in vector [-1,1])\n");
		return (FALSE);
	}
	coor->x = ft_atod(strs[0]);
	coor->y = ft_atod(strs[1]);
	coor->z = ft_atod(strs[2]);
	return (TRUE);
}
