/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/01 08:51:17 by eunwolee         ###   ########.fr       */
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
	while (i < info->num_philo)
	{
		if (get_time(&philo[i].time_start) == false)
			return (false); //이미 시작된 스레드들은?
		philo[i].time_last_eat = philo[i].time_start;
		pthread_create(&philo[i].id_thread, NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	// while (i < info->num_philo) //3-a
	// {
	// 	pthread_join(philo[i].id_thread, NULL);
	// 	i++;
	// }

	while (info->end == false) //3-b
	while (i < info->num_philo)
	{
		pthread_detach(philo[i].id_thread);
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

bool	check_end(t_philo *philo, t_info *info) //3번
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