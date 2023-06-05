/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/05 20:13:47 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	start(t_philo *philo, t_info *info);
void	set_start_time(t_philo *philo, t_info *info);
void	*routine(void *arg);
void	check_end(t_philo *philo, t_info *info);

void	start(t_philo *philo, t_info *info)
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
}

void	set_start_time(t_philo *philo, t_info *info)
{
	int	i;

	info->time_start = get_time();
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
		pass_time(info, info->time_to_eat);
	if (info->num_philo % 2
		&& philo->id_philo == info->num_philo - 1)
		pass_time(info, info->time_to_eat * 2);
	while (true)
	{
		if (take_fork(philo, info) == false \
			|| eating(philo, info) == false \
			|| sleeping(philo, info) == false \
			|| thinking(philo, info) == false)
			break ;
	}
	return (0);
}

void	check_end(t_philo *philo, t_info *info)
{
	int	i;
	
	while (info->end == false)
	{
		i = -1;
		while (++i < info->num_philo)
		{
			// printf("before %llu\n", get_time() - philo[i].time_last_eat);
			if (get_time() - philo[i].time_last_eat >= (uint64_t)info->time_to_die)
			{
				pthread_mutex_lock(&info->print);

				// printf("after %llu\n", get_time() - philo[i].time_last_eat);
				info->end = true;
				printf(DIE, get_time() - info->time_start, philo[i].id_philo + 1);
				pthread_mutex_unlock(&info->print);
				return ;
			}
		}
		if (info->eat_cnt == info->num_philo)
			info->end = true;
		usleep(info->num_philo * 20);
	}
}
