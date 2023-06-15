/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/16 08:40:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void		start(t_info *info);
bool		start_monitoring(t_info *info);
void		routine(t_info *info);
static void	set_start_time(t_info *info);

void	start(t_info *info)
{
	int	i;
	int	j;

	if (start_monitoring(info) == false)
		return ;
	set_start_time(info);
	i = -1;
	while (++i < info->num_philo)
	{
		if (i % 2)
			continue;
		info->philo.id_philo = i;
		info->philo.id_process[i] = fork();
		printf("i: %d, pid: %d\n", i, info->philo.id_process[i]);
		if (info->philo.id_process[i] == -1)
		{
			info->flag_error = true;
			print_error(PROCESS);
			break ;
		}
		else if (info->philo.id_process[i] == CHILD)
			routine(info);
	}
	i = -1;
	while (++i < info->num_philo)
	{
		if (!(i % 2))
			continue;
		info->philo.id_philo = i;
		info->philo.id_process[i] = fork();
		printf("i: %d, pid: %d\n", i, info->philo.id_process[i]);
		if (info->philo.id_process[i] == -1)
		{
			info->flag_error = true;
			print_error(PROCESS);
			break ;
		}
		else if (info->philo.id_process[i] == CHILD)
			routine(info);
	}
	if (info->flag_error == true)
	{
		j = -1;
		while (++j < i)
			kill(info->philo.id_process[j], SIGKILL);
		kill(info->monitor, SIGKILL);
	}
	check_end_main(info);
}

bool	start_monitoring(t_info *info)
{
	int	num;

	info->monitor = fork();
	if (info->monitor == -1)
		return (print_error(PROCESS));
	if (info->monitor == CHILD)
	{
		num = info->num_philo;
		while (num--)
			sem_wait(info->sem.check_eat);
		// exit(info->num_philo);
		exit(4);
	}
	return (true);
}

void	routine(t_info *info)
{
	// int	i;

	// if (info->philo.id_philo == info->num_philo - 1)
	// {
	// 	i = info->num_philo;
	// 	while (i--)
	// 		sem_post(info->sem.start);
	// }
	// else
	// 	sem_wait(info->sem.start);
	// if (info->philo.id_philo % 2)
	// 	pass_time(info, info->time_to_eat);
	// if (info->num_philo > 1 && info->num_philo % 2
	// 	&& info->philo.id_philo == info->num_philo - 1)
	// 	pass_time(info, info->time_to_eat * 2);
	while (true)
	{
		take_fork(info);
		eating(info);
		sleeping(info);
		thinking(info);
	}
	printf("%d\n", info->philo.id_philo+1);
}

static void	set_start_time(t_info *info)
{
	info->time_start = get_time();
	info->philo.time_last_eat = info->time_start;
}
