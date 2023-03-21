/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:23:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/21 22:07:00 by eunwolee         ###   ########.fr       */
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

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
} t_img;

int check_wall_row(t_map *map);
int check_wall_col(t_map *map);
int check_route(t_map *map);
t_map *get_map(int fd);
int create_map(t_map *map);
int create_collection(t_map *map, int col_num);
void init_collection(t_map *map);
int start_mlx(t_map *map);
int	free_n_print_out(int flag, int print, void *a, void *b);

#endif