/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/26 19:04:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

bool	eating(t_philo *philo, t_info *info)
{
	if (pthread_mutex_lock(&info->fork[philo->left]))
		return (false);
	if (print_state(philo, info, "has taken a left fork") == false)
	{
		pthread_mutex_unlock(&info->fork[philo->left]);
		return (false);
	}
	if (philo->left != philo->right)
	{
		if (pthread_mutex_lock(&info->fork[philo->right]))
		{
			pthread_mutex_unlock(&info->fork[philo->left]);
			return (false);
		}
		if (print_state(philo, info, "has taken a right fork") == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left]);
			pthread_mutex_unlock(&info->fork[philo->right]);
			return (false);
		}
	}
	if (print_state(philo, info, "is eating") == false)
	{
		pthread_mutex_unlock(&info->fork[philo->left]);
		pthread_mutex_unlock(&info->fork[philo->right]);
		return (false);
	}
	philo->eat_cnt++;
	if (pass_time(info->time_to_eat) == false)
	{
		pthread_mutex_unlock(&info->fork[philo->left]);
		pthread_mutex_unlock(&info->fork[philo->right]);
		return (false);
	}
	if (pthread_mutex_unlock(&info->fork[philo->left])
		|| pthread_mutex_unlock(&info->fork[philo->right]))
		return (false);
	return (true);
}

bool	sleeping(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, "is sleeping") == false
		|| pass_time(info->time_to_sleep) == false)
		return (false);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, "is thinking") == false)
		return (false);
	return (true);
}