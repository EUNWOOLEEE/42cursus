/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:22:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/23 16:44:16 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int start_game(t_map *map, t_vars *vars, t_data *data);

int start_mlx(t_map *map)
{
	t_vars *vars;
	t_data *data;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!vars || !data)
		return (free_n_print_out(2, 0, vars, data));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, map->width * 32, map->height * 32, "so_long");
	draw_map(map, vars);
	data->cur_row = map->start[0];
	data->cur_col = map->start[1];
	data->cur_dir = 1;
	data->map = map;
	data->vars = vars;
	start_game(map, vars, data);
	mlx_loop(vars->mlx);
	return (0);
}

int start_game(t_map *map, t_vars *vars, t_data *data)
{
	data->next_row = data->cur_row;
	data->next_col = data->cur_col;
	mlx_hook(vars->win, 2, 0, key_press, data);
	// mlx_hook(vars->win, 3, 0, key_release, data);
	mlx_loop_hook(vars->mlx, standing, data);

	(void)map;
	mlx_loop(vars->mlx);
	return (0);
}