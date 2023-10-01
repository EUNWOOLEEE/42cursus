/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:21:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/28 14:50:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_info	*init_info(int argc, char *file_neme)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info *));
	if (!info)
		return (NULL);
	if (check_argument(info, argc, file_neme) == FALSE)
	{
		free(info);
		return (NULL);
	}
	return (info);
}

t_bool	read_info(t_info *info)
{
	char	*buf;
	char	**strs;

	printf("1 %d\n", info->fd);
	buf = get_next_line(info->fd);
	printf("2 %d\n", info->fd);
	printf("read info before %s\n", buf);
	while (buf)
	{
		strs = ft_split(buf, ' ');
		if (!strs)
			return (FALSE);
		if (set_func(info, strs) == FALSE)
		{
			free_double_pointer(strs);
			return (FALSE);
		}
		free(buf);
		printf("3 %d\n", info->fd);
		buf = get_next_line(info->fd);
		printf("read info after %s\n", buf);
	}
	return (TRUE);
}

// t_bool	create_mlx()
// {
	
// }