/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:21:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/18 16:30:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

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
			break;
		strs = ft_split(buf, ' ');
		if (!strs)
			print_error_exit(MEMORY);
		free(buf);
		if (cnt_strs(strs) > 1) // 이거 맞나? 맑은 정신에 다시 생각해보기
			parse_func(scene, strs);
		// t_object *now = ft_lstlast(scene->world);
		// if (now)
		// 	printf("%d\n\n", now->num);
		free_double_pointer(strs);
	}
}
