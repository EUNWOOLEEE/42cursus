/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:35:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/23 16:55:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_valid_pos(t_data *data, int row, int col)
{
	if (data->map->map[row][col] == '1')
		return (-1);
	// if (data->map->map[row][col] == 'C')
	// {

	// }
	// if (data->map->map[row][col] == 'E') 캐릭터만 사라지고 종료
	return (0);
}

int key_press(int keycode, t_data *data)
{
	if ((keycode == 13 || keycode == 126) &&!check_valid_pos(data, data->next_row - 1, data->next_col))
	{
		data->next_row--;
		move_up(data);
	}
	else if ((keycode == 0 || keycode == 123))
	{
		data->cur_dir = 0;
		if (!check_valid_pos(data, data->next_row, data->next_col - 1))
		{
			data->next_col--;
			move_left(data);
		}
	}
	else if ((keycode == 1 || keycode == 125) && !check_valid_pos(data, data->next_row + 1, data->next_col))
	{
		data->next_row++;
		move_down(data);
	}
	else if ((keycode == 2 || keycode == 124))
	{
		data->cur_dir = 1;
		if (!check_valid_pos(data, data->next_row, data->next_col + 1))
		{
			data->next_col++;
			move_right(data);
		}
	}
	else if (keycode == 53)
	{
		data->exit++;
		return (0);
	}
	if (data->cur_row == data->next_row && data->cur_col == data->next_col)
		standing(data);
	data->cur_row = data->next_row;
	data->cur_col = data->next_col;
	return (0);
}

int key_release(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	printf("key release\n");
	return (0);
}

int standing(t_data *data)
{
	int stand;
	char *pos;

	stand = 0;
	if (!data->cur_dir)
		pos = ft_strdup("textures/standing/standing0-0.png");
	else
		pos = ft_strdup("textures/standing/standing1-0.png");
	if (data->cur_row == data->next_row && data->cur_col == data->next_col)
	{
		while (stand < 5)
		{
			// printf("%d %d %d %d\n", data->cur_row, data->next_row, data->cur_col, data->next_col);
			pos[28] = stand + '0';
			// printf("%s\n", pos);
			put_element(data->vars, "textures/map/grass.png", data->cur_row * 32, data->cur_col * 32);
			put_element(data->vars, pos, (data->cur_row * 32) + (32 * 0.25), (data->cur_col * 32) + (32 * 0.2));
			mlx_sync(2, data->vars->win);
			sleep(1);
			stand++;
		}
	}
	return (0);
}