/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:33:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 18:28:41 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_argument(t_info *info, int argc, char *file_name)
{
	int	extension;
	
	if (argc != 2)
	{
		printf("Usage: ./miniRT file.rt\n");
		return (FALSE);
	}
	extension = ft_strlen(file_name) - 3;
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
