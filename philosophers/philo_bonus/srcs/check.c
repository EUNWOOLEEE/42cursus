/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:43:07 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 20:39:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

bool	check_full(t_info *info);
void	check_end_main(t_info *info);
bool	check_end_philo(t_info *info, bool print);

bool	check_full(t_info *info)
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
		exit(info->num_philo);
	}
	return (true);
}

void	check_end_main(t_info *info)
{
	int	i;
	int	status;

	if (info->flag_error == true)
		return ;
	while (waitpid(-1, &status, 0) <= 0)
		continue ;
	i = -1;
	while (++i < info->num_philo)
	{
		if (status == i * 256)
			continue ;
		kill(info->philo.id_process[i], SIGKILL);
	}
	if (status != info->num_philo * 256)
		kill(info->monitor, SIGKILL);
}

bool	check_end_philo(t_info *info, bool print)
{
	if (get_time() - info->philo.time_last_eat >= (uint64_t)info->time_to_die)
	{
		if (print == false)
			sem_wait(info->sem.print);
		printf(DIE, PURPLE, get_time() - info->time_start, \
			info->philo.id_philo + 1, RESET);
		return (false);
	}
	return (true);
}
