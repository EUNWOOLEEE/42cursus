/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:22:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/28 19:18:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//x버튼으로 종료되게 하기
//exit로 종료되게 하기
//맨대토리에서 움직임 없게 하기
//mlx 함수들 리턴값 확인하기

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (free_n_print_out(0, 1, 0, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (free_n_print_out(0, 1, 0, 0));
	if (create_mlx(fd) == -1)
		return (free_n_print_out(0, 1, 0, 0));
	return (0);
}
