/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:43:07 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 16:35:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	check_end_main(t_info *info);
bool	check_end_philo(t_philo *philo, t_info *info, bool print);

void	check_end_main(t_info *info)
{
	while (true)
	{
		pthread_mutex_lock(&info->mutex.check_eat);
		pthread_mutex_lock(&info->mutex.check_end);
		if (info->eat_cnt == info->num_philo)
			info->flag_end = true;
		if (info->flag_end == true)
		{
			pthread_mutex_unlock(&info->mutex.check_end);
			pthread_mutex_unlock(&info->mutex.check_eat);
			return ;
		}
		pthread_mutex_unlock(&info->mutex.check_end);
		pthread_mutex_unlock(&info->mutex.check_eat);
	}
}

bool	check_end_philo(t_philo *philo, t_info *info, bool print)
{
	pthread_mutex_lock(&info->mutex.check_end);
	if (info->flag_end == true)
	{
		pthread_mutex_unlock(&info->mutex.check_end);
		return (false);
	}
	if (get_time() - philo->time_last_eat >= (uint64_t)info->time_to_die)
	{
		info->flag_end = true;
		pthread_mutex_unlock(&info->mutex.check_end);
		if (print == false)
			pthread_mutex_lock(&info->mutex.print);
		printf(DIE, PURPLE, get_time() - info->time_start, \
			philo->id_philo + 1, RESET);
		if (print == false)
			pthread_mutex_unlock(&info->mutex.print);
		return (false);
	}
	pthread_mutex_unlock(&info->mutex.check_end);
	return (true);
}
