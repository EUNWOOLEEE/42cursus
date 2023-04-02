/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:23:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/02 16:44:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	char	**tmp;
	int		height;
	int		width;
	int		start[2];
	int		exit[2];
	int		col_num;
	int		**collection;
}t_map;

typedef struct s_coor
{
	int	row;
	int	col;
}t_coor;

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}t_img;

typedef struct s_dis
{
	double	tree_row;
	double	tree_col;
	double	fruit_row;
	double	fruit_col;
	double	exit;
}t_dis;

typedef struct s_flag
{
	int	motion;
	int	fruit;
	int	stand;
	int	rest;
	int	sleep;
	int	goal;
	int	exit;
}t_flag;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		cur_dir;
	int		frame;
	int		move_cnt;
	t_coor	cur;
	t_coor	next;
	t_map	map;
	t_img	map_img[3];
	t_img	fruit[5];
	t_img	walk[2][8];
	t_img	stand[2][5];
	t_img	jump[2][11];
	t_img	rest[2][14];
	t_img	sleep[2][6];
	t_dis	dis;
	t_flag	flag;
}t_game;

void	create_mlx(int fd);
void	game_end(t_game *game);
void	get_map(t_game *game, int fd);
void	init_img(t_game *game);
void	stand_img(t_game *game, char *str);
void	walk_img(t_game *game, char *str);
void	jump_img(t_game *game, char *str);
void	rest_img(t_game *game, char *str);
void	sleep_img(t_game *game, char *str);
void	check_valid(t_game *game);
void	check_route(t_game *game);
void	draw_img(t_game *game, t_img img, double row, double col);
int		draw_map(t_game *game);
int		key_press(int keycode, t_game *game);
int		red_cross_press(t_game *game);
void	standing(t_game *game);
int		move_ready(t_game *game, int keycode);
int		walk_up(t_game *game, int walk, double *row, double *col);
int		walk_left(t_game *game, int walk, double *row, double *col);
int		walk_down(t_game *game, int walk, double *row, double *col);
int		walk_right(t_game *game, int walk, double *row, double *col);
int		jump_left(t_game *game, int jump, double *row, double *col);
int		jump_right(t_game *game, int jump, double *row, double *col);
void	error_exit(char *str);
void	print_move(int move_cnt);

#endif