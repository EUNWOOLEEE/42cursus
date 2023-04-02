/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:45 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/02 14:12:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	exit(1);
}

void	print_move(int move_cnt)
{
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(move_cnt, 1);
	ft_putchar_fd('\n', 1);
}

void	free_tmp(t_map **tmp, t_coor **queue)
{
	int	i;

	i = 0;
	while (i < (*tmp)->height)
	{
		free((*tmp)->map[i]);
		i++;
	}
	free((*tmp)->map);
	free(*tmp);
	free(*queue);
	tmp = 0;
	queue = 0;
}
