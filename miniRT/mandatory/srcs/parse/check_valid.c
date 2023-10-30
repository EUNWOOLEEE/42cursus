/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:33:43 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 14:35:03 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_argument(t_scene *scene, int argc, char *file_name);
t_bool	check_essential(t_scene *scene);

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

t_bool	check_essential(t_scene *scene)
{
	if (scene->cam.check_cam == FALSE \
		|| scene->light_com.check_ambient == FALSE \
		|| scene->light_com.check_specular == FALSE \
		|| scene->light.check_light == FALSE)
		return (FALSE);
	return (TRUE);
}
