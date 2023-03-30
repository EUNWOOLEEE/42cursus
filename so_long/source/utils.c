/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:45 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/30 13:36:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//지우기!!!!!!!!!!!
void print_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		for(int j = 0; j < map->width; j++)
			printf("%c", map->map[i][j]);
		printf("\n");
	}
}

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
