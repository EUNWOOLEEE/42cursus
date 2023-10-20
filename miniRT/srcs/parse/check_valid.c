/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:33:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 15:22:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_argument(t_scene *scene, int argc, char *file_name)
{
	int	extension;
	
	if (argc != 2)
		print_error_exit(USAGE_ARG);
	extension = ft_strlen(file_name) - 3;
	if (ft_strncmp(&file_name[extension], ".rt", 4))
		print_error_exit(USAGE_ARG);
	scene->fd = open(file_name, O_RDONLY);
	if (scene->fd == -1)
		print_error_exit("File open failure");
	return (TRUE);
}
