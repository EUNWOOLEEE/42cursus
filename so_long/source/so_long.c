/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:22:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/23 12:49:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	int fd;
	t_map *map;

	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (free_n_print_out(0, 1, 0, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (free_n_print_out(0, 1, 0, 0));
	map = get_map(fd);
	if (!map)
		return (free_n_print_out(0, 1, 0, 0));
	start_mlx(map);
	return (0);
}