/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 16:16:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// void asd()
// {
// 	system("leaks philo");
// }

int	main(int argc, char **argv)
{
	t_philo	*philo;

	// atexit(asd);
	
	if (argc != 5 && argc != 6)
		return (print_error(USAGE));
	philo = init(argc, argv);
	if (!philo)
		return (1);
	start(philo, philo->info);
	return (all_free(&philo, &philo->info));
}

// 5 800 200 200 (o 계속)
// 5 410 200 200 (o 죽음)
// 200 410 200 200 (x 빨리 죽음)
// 200 800 200 200 (o 계속)
// 199 610 200 200 (x 빨리 죽음)
// 시간이 0일 때 (자는시간이 0이면 빨리 죽음) -> 처리해야하나?
// 1명일 때 o