/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 19:46:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	take_fork(t_philo *philo, t_info *info, int first, int second);
bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

bool	take_fork(t_philo *philo, t_info *info, int first, int second)
{
	pthread_mutex_lock(&info->fork[first].mutex);
	info->fork[first].state = USING;
	if (print_state(philo, info, MSG_FORK) == false)
	{
		pthread_mutex_unlock(&info->fork[first].mutex);
		return (false);
	}
	pthread_mutex_lock(&info->fork[second].mutex);
	info->fork[second].state = USING;
	if (print_state(philo, info, MSG_FORK) == false)
	{
		pthread_mutex_unlock(&info->fork[first].mutex);
		pthread_mutex_unlock(&info->fork[second].mutex);
		return (false);
	}
	return (true);
}

bool	eating(t_philo *philo, t_info *info)
{
	int		first;
	int		second;

	if (philo->left < philo->right)
	{
		first = philo->left;
		second = philo->right;
	}
	else
	{
		first = philo->right;
		second = philo->left;
	}
	if (take_fork(philo, info, first, second) == false)
		return (false);
	get_time(&philo->time_last_eat);
	if (print_state(philo, info, MSG_EAT) == false)
	{
		pthread_mutex_unlock(&info->fork[first].mutex);
		pthread_mutex_unlock(&info->fork[second].mutex);
		return (false);
	}
	if (philo->eat_cnt >= 0)
		philo->eat_cnt++;
	pass_time(info->time_to_eat);
	info->fork[first].state = NOT_USING;
	info->fork[second].state = NOT_USING;
	pthread_mutex_unlock(&info->fork[first].mutex);
	pthread_mutex_unlock(&info->fork[second].mutex);
	return (true);
}

bool	sleeping(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, MSG_SLEEP) == false)
		return (false);
	pass_time(info->time_to_sleep);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, MSG_THINK) == false)
		return (false);
	return (true);
}
