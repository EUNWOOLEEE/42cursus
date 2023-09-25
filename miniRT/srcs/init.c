/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:21:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 07:47:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_info	*init_info(int argc, char *file_neme)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info *));
	if (!info)
		return (NULL);
	if (check_argument(argv, file_neme) == FALSE)
	{
		free(info);
		return (NULL);
	}
	return (info);
}

t_bool	read_info(t_info *info)
{
	char	buf[100];

	buf = get_next_line(info->fd);
	while (buf)
	{
		if (check_element(info, ft_split(buf, ' ')) == FALSE)
			return (FALSE);
		buf = get_next_line(info->fd);
	}
}

t_bool	create_mlx()
{
	
}