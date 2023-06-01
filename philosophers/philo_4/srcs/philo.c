/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/29 13:01:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./philo number_of_philosophers time_to_die time_to_eat
// time_to_sleep [number_of_times_each_philosopher_must_eat]

#include "../incs/philo.h"

int main(int argc, char **argv)
{
	t_philo	*philo;
	
	if (argc != 5 && argc != 6)
	{
		print_usage();
		return (1);
	}
	philo = init(argc, argv);
	if (!philo)
		return (1);
	start(philo, philo->info);
	if (philo->info->error == true)
		return (1);
	return (0);
}

// 5 800 200 200 (계속) -> 오래는 가는데 종료 포인트가 이상함
// 1 410 200 200 (죽음) o
// 5 410 200 200 (죽음)
// 200 410 200 200 x
// 199 610 200 200 x
// 4 300 200 100 (죽음) o
// 시간이 0일 때