/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/16 08:14:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

bool	take_fork(t_info *info);
bool	eating(t_info *info);
bool	sleeping(t_info *info);
bool	thinking(t_info *info);

bool	take_fork(t_info *info)
{
	sem_wait(info->sem.fork);
	sem_wait(info->sem.print);
	if (check_end_philo(info, true) == false)
		exit(info->philo.id_philo);
	// printf(FORK, GREEN, get_time() - info->time_start, info->philo.id_philo + 1, RESET);
	printf(FORK, get_time() - info->time_start, info->philo.id_philo + 1);
	sem_post(info->sem.print);
	if (info->num_philo == 1)
	{
		pass_time(info, info->time_to_die);
		exit(info->philo.id_philo);
	}
	sem_wait(info->sem.fork);
	sem_wait(info->sem.print);
	if (check_end_philo(info, true) == false)
		exit(info->philo.id_philo);
	// printf(FORK, GREEN, get_time() - info->time_start, info->philo.id_philo + 1, RESET);
	printf(FORK, get_time() - info->time_start, info->philo.id_philo + 1);
	return (true);
}

bool	eating(t_info *info)
{
	info->philo.time_last_eat = get_time();
	// printf(EAT, PINK, get_time() - info->time_start, info->philo.id_philo + 1, RESET);
	printf(EAT, get_time() - info->time_start, info->philo.id_philo + 1);
	info->philo.eat_cnt++;
	if (info->philo.eat_cnt == info->num_must_eat)
		sem_post(info->sem.check_eat);
	sem_post(info->sem.print);
	if (pass_time(info, info->time_to_eat) == false)
		exit(info->philo.id_philo);
	sem_post(info->sem.fork);
	sem_post(info->sem.fork);
	return (true);
}

bool	sleeping(t_info *info)
{
	sem_wait(info->sem.print);
	if (check_end_philo(info, true) == false)
		exit(info->philo.id_philo);
	// printf(SLEEP, YELLOW, get_time() - info->time_start, info->philo.id_philo + 1, RESET);
	printf(SLEEP, get_time() - info->time_start, info->philo.id_philo + 1);
	sem_post(info->sem.print);
	if (pass_time(info, info->time_to_sleep) == false)
		exit(info->philo.id_philo);
	return (true);
}

bool	thinking(t_info *info)
{
	sem_wait(info->sem.print);
	if (check_end_philo(info, true) == false)
		exit(info->philo.id_philo);
	// printf(THINK, PEACOCK, get_time() - info->time_start, info->philo.id_philo + 1, RESET);
	printf(THINK, get_time() - info->time_start, info->philo.id_philo + 1);
	sem_post(info->sem.print);
	if (info->time_to_think)
		if (pass_time(info, info->time_to_think) == false)
			exit(info->philo.id_philo);
	return (true);
}
