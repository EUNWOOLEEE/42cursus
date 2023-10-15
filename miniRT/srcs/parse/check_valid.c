/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:33:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/01 18:02:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_argument(t_info *info, int argc, char *file_name)
{
	int	extension;
	
	if (argc != 2)
		return (print_error_return("Usage: ./miniRT file.rt\n"));
	extension = ft_strlen(file_name) - 3;
	if (ft_strncmp(&file_name[extension], ".rt", 4))
		return (print_error_return("Usage: ./miniRT file.rt\n"));
	info->fd = open(file_name, O_RDONLY);
	if (info->fd == -1)
		return (print_error_return("File open failure"));
	return (TRUE);
}