/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/26 19:05:06 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	start(t_philo *philo, t_info *info);
void	*routine(void *arg);

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

	if (philo->philo_id % 2)
		pass_time(1000);
	while (info->end == false)
	{
		eating(philo, info);
		sleeping(philo, info);
		thinking(philo, info);

	}
	return (0);
}