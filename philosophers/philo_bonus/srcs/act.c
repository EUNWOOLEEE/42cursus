/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/12 08:11:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	take_fork(t_philo *philo, t_info *info);
bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

bool	take_fork(t_philo *philo, t_info *info)
{
	sem_wait(info->fork);
	sem_wait(info->print);
	if (check_end_philo(philo, info, true) == false)
		exit(1);
	// printf(FORK, GREEN, get_time() - info->time_start, philo->id_philo + 1, RESET);
	printf(FORK, get_time() - info->time_start, philo->id_philo + 1);
	sem_post(info->print);
	if (info->num_philo == 1)
	{
		pass_time(philo, info, info->time_to_die);
		exit(1);
	}
	sem_wait(info->fork);
	sem_wait(info->print);
	if (check_end_philo(philo, info, true) == false)
		exit(1);
	// printf(FORK, GREEN, get_time() - info->time_start, philo->id_philo + 1, RESET);
	printf(FORK, get_time() - info->time_start, philo->id_philo + 1);
	return (true);
}

bool	eating(t_philo *philo, t_info *info)
{
	philo->time_last_eat = get_time();
	// printf(EAT, PINK, get_time() - info->time_start, philo->id_philo + 1, RESET);
	printf(EAT, get_time() - info->time_start, philo->id_philo + 1);
	sem_wait(info->check_eat);
	philo->eat_cnt++;
	if (philo->eat_cnt == info->num_must_eat)
		sem_post(info->check_eat);
	sem_post(info->check_eat);
	sem_post(info->print);
	if (pass_time(philo, info, info->time_to_eat) == false)
		exit(1);
	sem_post(info->fork);
	sem_post(info->fork);
	return (true);
}

bool	sleeping(t_philo *philo, t_info *info)
{
	sem_wait(info->print);
	if (check_end_philo(philo, info, true) == false)
		exit(1);
	// printf(SLEEP, YELLOW, get_time() - info->time_start, philo->id_philo + 1, RESET);
	printf(SLEEP, get_time() - info->time_start, philo->id_philo + 1);
	sem_post(info->print);
	if (pass_time(philo, info, info->time_to_sleep) == false)
		return (false);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	sem_wait(info->print);
	if (check_end_philo(philo, info, true) == false)
		exit(1);
	// printf(THINK, PEACOCK, get_time() - info->time_start, philo->id_philo + 1, RESET);
	printf(THINK, get_time() - info->time_start, philo->id_philo + 1);
	sem_post(info->print);
	if (info->time_to_think)
		if (pass_time(philo, info, info->time_to_think) == false)
			return (false);
	return (true);
}
