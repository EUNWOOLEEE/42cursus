/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:33:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 08:57:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_bool	check_argument(t_info *info, int argc, char *file_name)
{
	int	extension = ft_strlen(file_name) - 3;
	
	if (argc != 2)
	{
		printf("Usage: ./miniRT file.rt\n");
		return (FALSE);
	}
	if (ft_strncmp(&file_name[extension], ".rt", 4))
	{
		printf("Usage: ./miniRT file.rt\n");
		return (FALSE);
	}
	info->fd = open(file_name, O_RDONLY);
	if (info->fd == -1)
		return (FALSE);
	return (TRUE);
}

int	cnt_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i++])
	return (i);
}

t_bool	emt_A(t_info *info, char **infos)
{
	if (cnt_strs(infos) != 3)
	{
		printf("Usage: A | ambient lighting ratio in range [0.0,1.0] | R,G,B [0-255]");
		return (FALSE);
	}
	info->A.light_ratio = ft_atod(infos[1]);
	// ambient lighting ratio in range [0.0,1.0]: 0.2 
	// R,G,B colors in range
}

t_bool	check_element(t_info *info, char **infos)
{
	if (!infos)
		return (FALSE);
	if (!ft_strncmp(infos[0], "A", 2))
	else if(!ft_strncmp(infos[0], "SR", 2))
	else if(!ft_strncmp(infos[0], "C", 2))
	else if(!ft_strncmp(infos[0], "L", 2))
	else if(!ft_strncmp(infos[0], "sp", 3))
	else if(!ft_strncmp(infos[0], "cl", 3))
	else if(!ft_strncmp(infos[0], "py", 3))
	else if(!ft_strncmp(infos[0], "co", 3))
}