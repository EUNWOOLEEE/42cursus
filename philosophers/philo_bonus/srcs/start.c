/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 20:47:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void		start(t_info *info);
static void	routine(t_info *info);
static void	set_start_time(t_info *info);
static void	kill_process(t_info *info, int i);

void	start(t_info *info)
{
	int	i;

	if (check_full(info) == false)
		return ;
	set_start_time(info);
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo.id_philo = i;
		info->philo.id_process[i] = fork();
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
		kill_process(info, i);
	check_end_main(info);
}

static void	routine(t_info *info)
{
	while (true)
	{
		take_fork(info);
		eating(info);
		sleeping(info);
		thinking(info);
	}
}

static void	set_start_time(t_info *info)
{
	info->time_start = get_time();
	info->philo.time_last_eat = info->time_start;
}

static void	kill_process(t_info *info, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		kill(info->philo.id_process[j], SIGKILL);
	kill(info->monitor, SIGKILL);
}
