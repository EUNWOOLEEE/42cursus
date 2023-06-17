/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 17:07:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool		take_fork(t_philo *philo, t_info *info);
bool		eating(t_philo *philo, t_info *info);
bool		sleeping(t_philo *philo, t_info *info);
bool		thinking(t_philo *philo, t_info *info);
static bool	ft_mutex_unlock(t_philo *philo, t_info *info, char *mode);

bool	take_fork(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->fork[philo->first].mutex);
	info->fork[philo->first].state = USING;
	pthread_mutex_lock(&info->mutex.print);
	if (check_end_philo(philo, info, true) == false)
		return (ft_mutex_unlock(philo, info, "110"));
	printf(FORK, GREEN, get_time() - info->time_start, \
		philo->id_philo + 1, RESET);
	pthread_mutex_unlock(&info->mutex.print);
	if (info->num_philo == 1)
	{
		pass_time(philo, info, info->time_to_die);
		return (ft_mutex_unlock(philo, info, "010"));
	}
	pthread_mutex_lock(&info->fork[philo->second].mutex);
	info->fork[philo->second].state = USING;
	pthread_mutex_lock(&info->mutex.print);
	if (check_end_philo(philo, info, true) == false)
		return (ft_mutex_unlock(philo, info, "111"));
	printf(FORK, GREEN, get_time() - info->time_start, \
		philo->id_philo + 1, RESET);
	return (true);
}

bool	eating(t_philo *philo, t_info *info)
{
	philo->time_last_eat = get_time();
	printf(EAT, PINK, get_time() - info->time_start, \
		philo->id_philo + 1, RESET);
	pthread_mutex_lock(&info->mutex.check_eat);
	philo->eat_cnt++;
	if (philo->eat_cnt == info->num_must_eat)
		info->eat_cnt++;
	pthread_mutex_unlock(&info->mutex.check_eat);
	pthread_mutex_unlock(&info->mutex.print);
	if (pass_time(philo, info, info->time_to_eat) == false)
		return (ft_mutex_unlock(philo, info, "011"));
	info->fork[philo->first].state = NOT_USING;
	pthread_mutex_unlock(&info->fork[philo->first].mutex);
	info->fork[philo->second].state = NOT_USING;
	pthread_mutex_unlock(&info->fork[philo->second].mutex);
	return (true);
}

bool	sleeping(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->mutex.print);
	if (check_end_philo(philo, info, true) == false)
		return (ft_mutex_unlock(philo, info, "100"));
	printf(SLEEP, YELLOW, get_time() - info->time_start, \
		philo->id_philo + 1, RESET);
	pthread_mutex_unlock(&info->mutex.print);
	if (pass_time(philo, info, info->time_to_sleep) == false)
		return (false);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->mutex.print);
	if (check_end_philo(philo, info, true) == false)
		return (ft_mutex_unlock(philo, info, "100"));
	printf(THINK, PEACOCK, get_time() - info->time_start, \
		philo->id_philo + 1, RESET);
	pthread_mutex_unlock(&info->mutex.print);
	if (info->time_to_think)
		if (pass_time(philo, info, info->time_to_think) == false)
			return (false);
	return (true);
}

static bool	ft_mutex_unlock(t_philo *philo, t_info *info, char *mode)
{
	if (mode[0] == '1')
		pthread_mutex_unlock(&info->mutex.print);
	if (mode[1] == '1')
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
	if (mode[2] == '1')
		pthread_mutex_unlock(&info->fork[philo->second].mutex);
	return (false);
}
