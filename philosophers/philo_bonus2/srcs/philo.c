/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/16 08:46:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

// 프로세스에 스레드 만들어서 프로세스는 죽음 모니터링하는 방법도 있음
// 포크가 테이블의 중앙에 있는거면 홀짝으로 나눌 필요가 없지 않나?

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
