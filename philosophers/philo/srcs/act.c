/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/04 18:13:31 by eunwolee         ###   ########.fr       */
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
	if (print_state(philo, info, FORK) == false)
	{
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
		return (false);
	}
	pthread_mutex_lock(&info->fork[philo->second].mutex);
	info->fork[philo->second].state = USING;
	if (print_state(philo, info, FORK) == false)
	{
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
		pthread_mutex_unlock(&info->fork[philo->second].mutex);
		return (false);
	}
	return (true);
}

bool	eating(t_philo *philo, t_info *info)
{
	if (take_fork(philo, info) == false)
		return (false);
	pthread_mutex_lock(&info->fork[philo->id_philo].eat);
	get_time(&philo->time_last_eat);
	if (print_state(philo, info, EAT) == false)
	{
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
		pthread_mutex_unlock(&info->fork[philo->second].mutex);
		return (false);
	}
	if (philo->eat_cnt >= 0)
		philo->eat_cnt++;
	pthread_mutex_unlock(&info->fork[philo->id_philo].eat);
	pass_time(info->time_to_eat);
	info->fork[philo->first].state = NOT_USING;
	info->fork[philo->second].state = NOT_USING;
	pthread_mutex_unlock(&info->fork[philo->first].mutex);
	pthread_mutex_unlock(&info->fork[philo->second].mutex);
	return (true);
}

bool	sleeping(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, SLEEP) == false)
		return (false);
	pass_time(info->time_to_sleep);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, THINK) == false)
		return (false);
	if (info->scheduling == true)
		pass_time(info->time_to_eat * 2 - info->time_to_sleep);
	return (true);
}
