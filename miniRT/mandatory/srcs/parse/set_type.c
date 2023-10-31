/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:04:36 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/31 15:43:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void		parse_func(t_scene *scene, char **strs);
t_bool		parse_color(t_color *rgb, char **strs);
t_bool		parse_coor(t_vec *coor, char **strs);
t_bool		parse_double(double *d, char *str);

void	parse_func(t_scene *scene, char **strs)
{
	if (!ft_strncmp(strs[0], "A", 2))
		ambient(scene, strs);
	else if (!ft_strncmp(strs[0], "C", 2))
		cam(scene, strs);
	else if (!ft_strncmp(strs[0], "L", 2))
		light(scene, strs);
	else if (!ft_strncmp(strs[0], "sp", 3))
		ft_lstadd_back(&scene->world, object(sphere(strs), SP));
	else if (!ft_strncmp(strs[0], "pl", 3))
		ft_lstadd_back(&scene->world, object(plane(strs), PL));
	else if (!ft_strncmp(strs[0], "cy", 3))
		ft_lstadd_back(&scene->world, object(cylinder(strs), CY));
	else if (!ft_strncmp(strs[0], "co", 3))
		ft_lstadd_back(&scene->world, object(cone(strs), CO));
	else
		print_error_exit(NOTALLOWED);
}

t_bool	parse_color(t_color *rgb, char **strs)
{
	int	i;

	if (!strs)
		return (FALSE);
	if (cnt_strs(strs) != 3)
	{
		free_double_pointer(strs);
		return (FALSE);
	}
	i = -1;
	while (strs[++i])
	{
		if (check_int_char(strs[i]) == FALSE)
		{
			free_double_pointer(strs);
			return (FALSE);
		}
	}
	rgb->x = (long long)ft_atoi(strs[0]);
	rgb->y = (long long)ft_atoi(strs[1]);
	rgb->z = (long long)ft_atoi(strs[2]);
	free_double_pointer(strs);
	return (TRUE);
}

t_bool	parse_coor(t_vec *coor, char **strs)
{
	int	i;

	if (!strs)
		return (FALSE);
	if (cnt_strs(strs) != 3)
	{
		free_double_pointer(strs);
		return (FALSE);
	}
	i = -1;
	while (strs[++i])
	{
		if (check_double_char(strs[i]) == FALSE)
		{
			free_double_pointer(strs);
			return (FALSE);
		}
	}
	coor->x = ft_atod(strs[0]);
	coor->y = ft_atod(strs[1]);
	coor->z = ft_atod(strs[2]);
	free_double_pointer(strs);
	return (TRUE);
}

t_bool	parse_double(double *d, char *str)
{
	if (check_double_char(str) == FALSE)
		return (FALSE);
	*d = ft_atod(str);
	return (TRUE);
}
