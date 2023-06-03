/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 18:22:14 by eunwolee         ###   ########.fr       */
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
		print_error(usage_msg);
		return (1);
	}
	philo = init(argc, argv);
	if (!philo)
		return (1);
	start(philo, philo->info);
	return (all_free(&philo, &philo->info));
}

// 5 800 200 200 (계속) -> 오래는 가는데 종료 포인트가 이상함
// 5 410 200 200 (죽음)
// 200 410 200 200 x
// 200 800 200 200 x
// 199 610 200 200 x
// 시간이 0일 때 o