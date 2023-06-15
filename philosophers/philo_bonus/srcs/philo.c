/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/14 16:08:29 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

//	배부름 감지하는 모니터링 프로세스 하나 더 만들기
//	프로세스에 스레드 만들어서 프로세스는 죽음 모니터링하기
// void asd()
// {
// 	system("leaks philo");
// }

int	main(int argc, char **argv)
{
	t_info *info;

	// atexit(asd);
	
	if (argc != 5 && argc != 6)
		return (print_error(USAGE));
	info = init(argc, argv);
	if (!info)
		return (1);
	start(info);
	return (all_free(&info));
}
