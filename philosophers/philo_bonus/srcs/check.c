/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:43:07 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/12 07:48:39 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	check_end_main(t_info *info);
bool	check_end_philo(t_philo *philo, t_info *info, bool print);

void	check_end_main(t_info *info)
{
	while (true)
	{
		sem_wait(info->check_eat);
		sem_wait(info->check_end);
		if (info->eat_cnt == info->num_philo)
			info->end = true;
		if (info->end == true)
		{
			sem_post(info->check_end);
			sem_post(info->check_eat);
			return ;
		}
		sem_post(info->check_end);
		sem_post(info->check_eat);
	}
}

bool	check_end_philo(t_philo *philo, t_info *info, bool print)
{
	sem_wait(info->check_end);
	if (info->end == true)
	{
		sem_post(info->check_end);
		return (false);
	}
	if (get_time() - philo->time_last_eat >= (uint64_t)info->time_to_die)
	{
		if (print == false)
			sem_wait(info->print);
		info->end = true;
		// printf(DIE, PURPLE, get_time() - info->time_start, philo->id_philo + 1, RESET);
		printf(DIE, get_time() - info->time_start, philo->id_philo + 1);
		sem_post(info->print);
		sem_post(info->check_end);
		return (false);
	}
	sem_post(info->check_end);
	return (true);
}
