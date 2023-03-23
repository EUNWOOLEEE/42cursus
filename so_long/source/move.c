/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:04:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/23 16:47:16 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int move_right(t_data *data)
{
	int move;
	double dis;
	char *pos;

	move = 0;
	dis = 0.13;
	pos = ft_strdup("textures/moving/moving1-0.png");
	if (!pos)
		return (0);
	while (move <= 8)
	{
		pos[24] = move % 8 + '0';
		put_element(data->vars, "textures/map/grass.png", data->next_row * 32, data->next_col * 32);
		put_element(data->vars, "textures/map/grass.png", (data->next_row) * 32, (data->next_col - 1) * 32);
		put_element(data->vars, pos, (double)(data->cur_row * 32) + (32 * 0.25), (double)(data->cur_col * 32) + (32 * dis));
		mlx_sync(2, data->vars->win);
		sleep(1);
		dis += 0.13;
		move++;
	}
	return (free_n_print_out(1, 0, pos, 0));
}

int move_left(t_data *data)
{
	int move;
	double dis;
	char *pos;

	move = 0;
	dis = 0.09;
	pos = ft_strdup("textures/moving/moving0-0.png");
	if (!pos)
		return (0);
	while (move <= 8)
	{
		pos[24] = move % 8 + '0';
		put_element(data->vars, "textures/map/grass.png", data->next_row * 32, data->next_col * 32);
		put_element(data->vars, "textures/map/grass.png", (data->next_row) * 32, (data->next_col + 1) * 32);
		put_element(data->vars, pos, (double)(data->cur_row * 32) + (32 * 0.25), (double)(data->cur_col * 32) - (32 * dis));
		mlx_sync(2, data->vars->win);
		sleep(1);
		dis += 0.09;
		move++;
	}
	return (free_n_print_out(1, 0, pos, 0));
}

int move_up(t_data *data)
{
	int move;
	double dis;
	char *pos;

	move = 0;
	dis = 0.08;
	if (!data->cur_dir)
		pos = ft_strdup("textures/moving/moving0-0.png");
	else
		pos = ft_strdup("textures/moving/moving1-0.png");
	if (!pos)
		return (0);
	while (move <= 8)
	{
		pos[24] = move % 8 + '0';
		put_element(data->vars, "textures/map/grass.png", data->next_row * 32, data->next_col * 32);
		put_element(data->vars, "textures/map/grass.png", (data->next_row + 1) * 32, (data->next_col) * 32);
		put_element(data->vars, pos, (double)(data->cur_row * 32) - (32 * dis), (double)(data->cur_col * 32) + (32 * 0.2));
		mlx_sync(2, data->vars->win);
		sleep(1);
		dis += 0.08;
		move++;
	}
	return (free_n_print_out(1, 0, pos, 0));
}

int move_down(t_data *data)
{
	int move;
	double dis;
	char *pos;

	move = 0;
	dis = 0.14;
	if (!data->cur_dir)
		pos = ft_strdup("textures/moving/moving0-0.png");
	else
		pos = ft_strdup("textures/moving/moving1-0.png");
	if (!pos)
		return (0);
	while (move <= 8)
	{
		pos[24] = move % 8 + '0';
		put_element(data->vars, "textures/map/grass.png", data->next_row * 32, data->next_col * 32);
		put_element(data->vars, "textures/map/grass.png", (data->next_row - 1) * 32, (data->next_col) * 32);
		put_element(data->vars, pos, (double)(data->cur_row * 32) + (32 * dis), (double)(data->cur_col * 32) + (32 * 0.2));
		mlx_sync(2, data->vars->win);
		sleep(1);
		dis += 0.14;
		move++;
	}
	return (free_n_print_out(1, 0, pos, 0));
}
