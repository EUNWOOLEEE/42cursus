/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/12 08:11:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void		start(t_philo *philo, t_info *info);
void		routine(t_philo *philo, t_info *info);
static void	set_start_time(t_philo *philo, t_info *info);

void	start(t_philo *philo, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	sem_wait(info->start);
	set_start_time(philo, info);
	while (++i < info->num_philo)
	{
		philo[i].id_process = fork();
		if (philo[i].id_process == -1)
		{
			info->error = true;
			info->end = true;
			print_error(PROCESS);
			break ;
		}
		if (philo[i].id_process == CHILD)
			routine(&philo[i], info);
	}
	sem_post(info->start);
	check_end_main(info);
	j = -1;
	while (++j < i)
		waitpid(philo[j].id_process, NULL, 0);
}

void	routine(t_philo *philo, t_info *info)
{
	sem_wait(info->check_eat);
	sem_wait(info->start);
	sem_post(info->start);
	if (philo->id_philo % 2)
		pass_time(philo, info, info->time_to_eat);
	if (info->num_philo > 1 && info->num_philo % 2
		&& philo->id_philo == info->num_philo - 1)
		pass_time(philo, info, info->time_to_eat * 2);
	while (true)
	{
		if (take_fork(philo, info) == false \
			|| eating(philo, info) == false \
			|| sleeping(philo, info) == false \
			|| thinking(philo, info) == false)
			break ;
	}
}

static void	set_start_time(t_philo *philo, t_info *info)
{
	int	i;

	info->time_start = get_time();
	i = -1;
	while (++i < info->num_philo)
		philo[i].time_last_eat = info->time_start;
}
