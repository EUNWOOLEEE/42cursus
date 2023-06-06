/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/06 14:58:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	take_fork(t_philo *philo, t_info *info);
bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

bool	take_fork(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->fork[philo->first].mutex);
	info->fork[philo->first].state = USING;
	printf("a %d\n", philo->id_philo+1);
	pthread_mutex_lock(&info->print);
	printf("a m %d\n", philo->id_philo+1);
	if (info->end == true)
	{
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
		pthread_mutex_unlock(&info->print);
		return (false);
	}
	printf(FORK, get_time() - info->time_start, philo->id_philo + 1);
	pthread_mutex_unlock(&info->print);
	pthread_mutex_lock(&info->fork[philo->second].mutex);
	info->fork[philo->second].state = USING;
	printf("b %d\n", philo->id_philo+1);
	pthread_mutex_lock(&info->print);
	printf("b m %d\n", philo->id_philo+1);
	if (info->end == true)
	{
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
		pthread_mutex_unlock(&info->fork[philo->second].mutex);
		pthread_mutex_unlock(&info->print);
		return (false);
	}
	printf(FORK, get_time() - info->time_start, philo->id_philo + 1);
	return (true);
}

bool	eating(t_philo *philo, t_info *info)
{
	philo->time_last_eat = get_time();
	printf(EAT, get_time() - info->time_start, philo->id_philo + 1);
	philo->eat_cnt++;
	if (philo->eat_cnt == info->num_must_eat)
		info->eat_cnt++;
	pthread_mutex_unlock(&info->print);
	pass_time(info, info->time_to_eat);
	if (info->end == true)
	{
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
		pthread_mutex_unlock(&info->fork[philo->second].mutex);
		return (false);
	}
	info->fork[philo->first].state = NOT_USING;
	pthread_mutex_unlock(&info->fork[philo->first].mutex);
	info->fork[philo->second].state = NOT_USING;
	pthread_mutex_unlock(&info->fork[philo->second].mutex);
	return (true);
}

bool	sleeping(t_philo *philo, t_info *info)
{
	printf("d %d\n", philo->id_philo+1);
	pthread_mutex_lock(&info->print);
	printf("d m %d\n", philo->id_philo+1);
	if (info->end == true)
	{
		pthread_mutex_unlock(&info->print);
		return (false);
	}
	printf(SLEEP, get_time() - info->time_start, philo->id_philo + 1);
	pthread_mutex_unlock(&info->print);
	pass_time(info, info->time_to_sleep);
	if (info->end == true)
		return (false);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	printf("e %d\n", philo->id_philo+1);
	pthread_mutex_lock(&info->print);
	printf("e m %d\n", philo->id_philo+1);
	if (info->end == true)
	{
		pthread_mutex_unlock(&info->print);
		return (false);
	}
	printf(THINK, get_time() - info->time_start, philo->id_philo + 1);
	pthread_mutex_unlock(&info->print);
	if (info->scheduling == true)
	{
		pass_time(info, info->time_to_eat * 2 - info->time_to_sleep);
		if (info->end == true)
			return (false);
	}
	return (true);
}
