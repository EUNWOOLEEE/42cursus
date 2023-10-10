/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:07:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/01 19:21:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int main(int argc, char **argv)
{
	t_info	*info;
	
	info = init_info(argc, argv[1]);
	if (!info)
		return (0);
	if (read_info(info) == FALSE)
	{
		close(info->fd);
		free(info);
		return (0);
	}

	create_mlx(info);
	// print_infos(info);
	return (0);
}