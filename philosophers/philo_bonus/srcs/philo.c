/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/16 14:56:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

// 생성되는 순서대로 시작

// void asd()
// {
// 	system("leaks philo");
// }

int	main(int argc, char **argv)
{
	t_info *info;

	if (argc != 5 && argc != 6)
		return (print_error(USAGE));
	info = init(argc, argv);
	if (!info)
		return (1);
	start(info);
	// atexit(asd);
	return (all_free(&info));
}
