/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:39:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/25 12:14:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// ./philo [number_of_philosophers] [time_to_die] [time_to_eat]
//  [time_to_sleep] [number_of_times_each_philosopher_must_eat]

int main(int argc, char **argv)
{
	t_philo	*philo;
	
	if (argc != 5 && argc != 6)
		return (1); //usage
	philo = init(argc, argv);
	if (!philo)
		return (1);
	start(philo, philo[0].info);
	return (0);
}

//먹는 시간을 0초로 두면 2밀리초 텀이 생김
//자는 시간이 0이면?