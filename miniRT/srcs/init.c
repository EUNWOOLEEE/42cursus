/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:21:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 18:16:25 by eunwolee         ###   ########.fr       */
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

	buf = get_next_line(info->fd);
	while (buf)
	{
		strs = ft_split(buf, ' ');
		if (!strs)
			return (FALSE);
		if (check_element(info, strs) == FALSE \
			|| check_object(info, strs) == FALSE)
		{
			free_double_pointer(strs);
			return (FALSE);
		}
		free(buf);
		buf = get_next_line(info->fd);
	}
	return (TRUE);
}

// t_bool	create_mlx()
// {
	
// }