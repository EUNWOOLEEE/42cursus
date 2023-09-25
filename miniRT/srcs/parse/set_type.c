/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:17:56 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 18:22:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	set_element(t_info *info, char **strs)
{
	if (!ft_strncmp(strs[0], "A", 2))
	{
		if (emt_A(&(info->A), strs) == FALSE)
			return (FALSE);
	}
	else if(!ft_strncmp(strs[0], "SR", 2))
	{
		if (emt_SR(&(info->SR), strs) == FALSE)
			return (FALSE);
	}
	else if(!ft_strncmp(strs[0], "C", 2))
	{
		if (emt_C(&(info->C), strs) == FALSE)
			return (FALSE);
	}
	else if(!ft_strncmp(strs[0], "L", 2))
	{
		if (emt_L(&(info->L), strs) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	set_object(t_info *info, char **strs)
{
	if(!ft_strncmp(strs[0], "sp", 3))
	{
		if (obj_sp(&(info->sp), strs) == FALSE)
			return (FALSE);
	}
	else if(!ft_strncmp(strs[0], "pl", 3))
	{
		if (obj_pl(&(info->pl), strs) == FALSE)
			return (FALSE);
	}
	else if(!ft_strncmp(strs[0], "cy", 3))
	{
		if (obj_cy(&(info->cy), strs) == FALSE)
			return (FALSE);
	}
	else if(!ft_strncmp(strs[0], "co", 3))
	{
		if (obj_co(&(info->co), strs) == FALSE)
			return (FALSE);
	}
	return (TRUE);
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
