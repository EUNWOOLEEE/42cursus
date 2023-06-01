/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/31 17:55:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	start(t_philo *philo, t_info *info);
void	*routine(void *arg);
bool	check_end(t_philo *philo, t_info *info);

bool	start(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	if (get_time(&info->time_to_start) == false)
		return (false);
	while (i < info->num_philo)
	{
		philo[i].time_last_eat = info->time_to_start;
		pthread_create(&philo[i].thread_id, NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;

	// if (philo->philo_id % 2)
	// 	pass_time(1);
	while (info->end == false)
	{
		if (eating(philo, info) == false
			|| sleeping(philo, info) == false
			|| thinking(philo, info) == false)
		{
			info->error = true;
			break;
		}
	}
	return (0);
}

//죽음 체크하는 타이밍이랑 방법 다시 확인하기
//1. 각 철학자를 체크하는 스레드 만들기
//2. 메인 스레드에서 감시하기
//3. 지금처럼 각 스레드가 죽음 체크하기

//a. 각 스레드가 알아서 종료하기
//b. 메인 스레드가 종료시키기
bool	check_end(t_philo *philo, t_info *info)
{
	uint64_t	cur;

	if (get_time(&cur) == false)
		return (false);
	if (pthread_mutex_lock(&info->end_lock))
		return (false);
	if (info->end == false
		&& cur - philo->time_last_eat >= info->time_to_die)
	{
		print_state(philo, info, "died");
		info->end = true;
	}
	if (info->end == false && info->num_must_eat
		&& philo->eat_cnt == info->num_must_eat)
	{
		print_state(philo, info, "is full"); //출력 안 해야 함
		info->end = true;
	}
	if (pthread_mutex_unlock(&info->end_lock))
		return (false);
	return (true);
}