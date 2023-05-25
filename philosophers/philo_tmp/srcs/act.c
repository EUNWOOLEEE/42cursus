/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:55:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/25 12:13:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_bool eating(t_philo *philo, t_info *info)
{
	if (info->end == TRUE)
		return (TRUE);
	if (pthread_mutex_lock(&info->forks[philo->left]))
		return (FALSE);
	print_time(philo, info, "has taken a left fork");
	// print_time(philo, info, "has taken a fork");
	if (info->num_philo == 1)
	{
		pass_time(info->time_die);
		pthread_mutex_unlock(&info->forks[philo->left]);
		return (TRUE);
	}
	if (pthread_mutex_lock(&info->forks[philo->right]))
	{
		pthread_mutex_unlock(&info->forks[philo->left]); //이게 또 실패하면? 함수를 따로 만들까?
		return (FALSE);
	}
	print_time(philo, info, "has taken a right fork");
	// print_time(philo, info, "has taken a fork");
	print_time(philo, info, "is eating");
	philo->eat_cnt++;
	get_cur_time(&philo->last_eat_time);
	// printf("%d\n", philo->eat_cnt);
	pass_time(info->time_eat);
	pthread_mutex_unlock(&info->forks[philo->left]);
	pthread_mutex_unlock(&info->forks[philo->right]); //에러처리를 얼마나 해야하는건가..
	return (TRUE);
}

void sleeping(t_philo *philo, t_info *info)
{
	if(info->end == TRUE)
		return ;
	print_time(philo, info, "is sleeping");
	pass_time(info->time_sleep);
}

void thinking(t_philo *philo, t_info *info)
{
	if(info->end == TRUE)
		return ;
	print_time(philo, info, "is thinking");
}