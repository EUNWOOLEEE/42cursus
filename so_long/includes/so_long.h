/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:23:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/24 22:23:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>

# include "../mlx_mac/mlx.h"
# include "../Libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	char **map;
	int height;
	int width;
	int start[2];
	int exit[2];
	int col_num;
	int **collection;
} t_map;

typedef struct s_coor
{
	int row;
	int col;
} t_coor;

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
} t_img;

typedef struct s_pos
{
	double tree_row;
	double tree_col;
	double exit;
	double fox_row;
	double fox_col;
	double fruit_row;
	double fruit_col;
} t_pos;

typedef struct s_flag
{
	int fruit;
	int exit;
} t_flag;

typedef struct s_game
{
	void *mlx;
	void *win;
	double dis;
	int cur_dir;
	int frame;
	t_coor cur;
	t_coor next;
	t_map *map;
	t_img map_img[3];
	t_img fruit[5];
	t_img walk[2][8];
	t_img stand[2][5];
	t_img jump[11];
	t_pos pos;
	t_flag flag;
} t_game;

int move(t_game *game, int direction);
void draw_sprite(t_game *game, t_img img, double row, double col);
int img_init(t_game *game);
int check_wall_row(t_map *map);
int check_wall_col(t_map *map);
int check_route(t_map *map);
t_map *get_map(int fd);
int create_map(t_map *map);
int create_collection(t_map *map, int col_num);
void init_collection(t_map *map);
int start_mlx(t_map *map);
int draw_map(t_game *map);
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);
int standing(t_game *game);
int walk_up(t_game *game, int walk, double *row, double *col);
int walk_left(t_game *game, int walk, double *row, double *col);
int walk_down(t_game *game, int walk, double *row, double *col);
int walk_right(t_game *game, int walk, double *row, double *col);

int	free_n_print_out(int flag, int print, void *a, void *b);

#endif