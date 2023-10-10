/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:21:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/01 19:39:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_info	*init_info(int argc, char *file_neme)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
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

	while (TRUE)
	{
		buf = get_next_line(info->fd);
		if (!buf)
			break;
		strs = ft_split(buf, ' ');
		if (!strs)
			return (FALSE);
		free(buf);
		if (cnt_strs(strs) > 1)
		{
			if (set_func(info, strs) == FALSE)
			{
				free_double_pointer(strs);
				return (FALSE);
			}
		}
		free_double_pointer(strs);
	}
	return (TRUE);
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	return (0);
}

int	red_cross_press(void)
{
	exit(0);
}

t_bool	create_mlx(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1000, 600, "miniRT");
	if (!info->mlx || !info->win)
		return (FALSE);
	mlx_hook(info->win, 2, 0, key_press, info);
	mlx_hook(info->win, 17, 0, red_cross_press, info);
	mlx_loop(info->mlx);
	return (TRUE);
}