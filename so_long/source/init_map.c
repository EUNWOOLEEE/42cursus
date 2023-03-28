/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:23:08 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/28 19:45:06 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*0 : 빈 공간
1 : 벽
C : 수집품
E : 맵의 출구
P : 캐릭터의 시작 지점*/

static t_list	*get_map_line(int fd);
static int		fill_map(t_map *map, t_list *list);
static int		check_char(t_map *map, char c, int h, int w);

t_map	*get_map(int fd)
{
	t_list	*head;
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	head = get_map_line(fd);
	map->width = ft_strlen(head->content) - 1; //개행
	map->height = ft_lstsize(head);
	create_map(map);
	if (fill_map(map, head) == -1)
		return (0);
	ft_lstclear(&head, free);
	if (check_wall_row(map) == -1 || check_wall_col(map) == -1
		|| create_collection(map, map->col_num) == -1)
		return (0);
	init_collection(map);
	if (!map->start[0] || !map->exit[0] || !map->collection[0][0]
		|| check_route(map) == -1)
		return (0);
	return (map);
}

int	create_map(t_map *map)
{
	int	idx;

	idx = 0;
	map->map = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		return (-1);
	while (idx < map->height)
	{
		map->map[idx] = (char *)ft_calloc(map->width + 1, sizeof(char));
		if (!map->map[idx])
		{
			while (idx--)
				free(map->map[idx]);
			return (-1);
		}
		idx++;
	}
	return (0);
}

static t_list	*get_map_line(int fd)
{
	t_list	*head;
	t_list	*new;
	char	*str;

	head = 0;
	str = get_next_line(fd);
	while (str)
	{
		new = ft_lstnew(str);
		ft_lstadd_back(&head, new);
		str = get_next_line(fd);
	}
	return (head);
}

static int	fill_map(t_map *map, t_list *list)
{
	t_coor	coor;
	int		res;

	coor.row = 0;
	while (coor.row < map->height)
	{
		coor.col = 0;
		while (coor.col < map->width)
		{
			res = check_char(map, list->content[coor.col], coor.row, coor.col);
			if (res == -1)
			{
				ft_lstclear(&list, free);
				return (free_n_print_out(2, 0, map, 0));
			}
			coor.col++;
		}
		map->map[coor.row][coor.col] = '\0';
		list = list->next;
		coor.row++;
	}
	return (0);
}

static int	check_char(t_map *map, char c, int row, int col)
{
	if (c == 'P')
	{
		if (map->start[0])
			return (-1);
		map->start[0] = row;
		map->start[1] = col;
	}
	else if (c == 'E')
	{
		if (map->exit[0])
			return (-1);
		map->exit[0] = row;
		map->exit[1] = col;
	}
	else if (c == 'C')
		map->col_num++;
	else if (c != '0' && c != '1')
		return (-1);
	map->map[row][col] = c;
	return (0);
}
