/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:58:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 12:58:56 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_scene		*scene_init(int argc, char *file_neme);
void		scene_read(t_scene *scene);

t_scene	*scene_init(int argc, char *file_neme)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		print_error_exit(MEMORY);
	if (check_argument(scene, argc, file_neme) == FALSE)
		print_error_exit(MEMORY);
	return (scene);
}

void	scene_read(t_scene *scene)
{
	char	*buf;
	char	**strs;

	while (TRUE)
	{
		buf = get_next_line(scene->fd);
		if (!buf)
			break ;
		strs = ft_split(buf, ' ');
		if (!strs)
			print_error_exit(MEMORY);
		free(buf);
		if (cnt_strs(strs) > 1)
			parse_func(scene, strs);
		else if (strs[0][0] != '\n')
			print_error_exit(NOTALLOWED);
		free_double_pointer(strs);
	}
	if (check_essential(scene) == FALSE)
		print_error_exit(LACK);
}
