/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:55:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/12 15:08:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_bool eating(t_philo *philo, t_info *info)
{
	if (pthread_mutex_lock(&info->forks[philo->left]))
		return (FALSE);
	print_time(philo, info, "has taken a left fork");
	if (pthread_mutex_lock(&info->forks[philo->right]))
	{
		pthread_mutex_unlock(&info->forks[philo->left]); //이게 또 실패하면?
		return (FALSE);
	}
	print_time(philo, info, "has taken a right fork");
	print_time(philo, info, "is eating");
	get_cur_time(&philo->last_eat_time);
	philo->eat_cnt++;
	pthread_mutex_unlock(&info->forks[philo->left]);
	pthread_mutex_unlock(&info->forks[philo->right]); //에러처리를 얼마나 해야하는건가..
	return (TRUE);
}

void sleeping(t_philo *philo, t_info *info)
{
	print_time(philo, info, "is thinking");
	usleep(info->time_sleep);
}

void thinking(t_philo *philo, t_info *info)
{
	print_time(philo, info, "is thinking");
}