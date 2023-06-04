/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/04 18:07:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	start(t_philo *philo, t_info *info);
void	set_start_time(t_philo *philo, t_info *info);
void	*routine(void *arg);
void	check_end(t_philo *philo, t_info *info);

bool	start(t_philo *philo, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	pthread_mutex_lock(&info->start);
	while (++i < info->num_philo)
	{
		if (pthread_create(&philo[i].id_thread, NULL, routine, &philo[i]))
		{
			info->error = true;
			info->end = true;
			break ;
		}
	}
	set_start_time(philo, info);
	pthread_mutex_unlock(&info->start);
	check_end(philo, info);
	j = -1;
	while (++j < i)
		pthread_join(philo[j].id_thread, NULL);
	return (true);
}

void	set_start_time(t_philo *philo, t_info *info)
{
	int	i;

	get_time(&info->time_start);
	i = -1;
	while (++i < info->num_philo)
		philo[i].time_last_eat = info->time_start;
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	pthread_mutex_lock(&info->start);
	pthread_mutex_unlock(&info->start);
	if (philo->id_philo % 2)
		pass_time(info->time_to_eat);
	if (info->num_philo % 2
		&& philo->id_philo == info->num_philo - 1)
		pass_time(info->time_to_eat * 2);
	while (true)
	{
		if (eating(philo, info) == false \
			|| sleeping(philo, info) == false \
			|| thinking(philo, info) == false)
			break ;
	}
	return (0);
}
