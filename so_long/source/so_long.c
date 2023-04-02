/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:22:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/02 14:11:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//같은 내용으로 bonus 파일 만들고 makefile rule 추가하기

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error_exit(0);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		error_exit("Filename extension is not \".ber\"\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		error_exit(0);
	create_mlx(fd);
	return (0);
}
