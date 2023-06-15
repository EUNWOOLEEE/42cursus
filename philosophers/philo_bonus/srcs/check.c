/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:43:07 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/16 08:18:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void	check_end_main(t_info *info);
bool	check_end_philo(t_info *info, bool print);

void	check_end_main(t_info *info)
{
	int	i;
	int	status;

	if (info->flag_error == true)
		return ;
	while (waitpid(-1, &status, 0) <= 0)
		continue;
	i = -1;
	while (++i < info->num_philo)
		kill(info->philo.id_process[i], SIGKILL);
	if (status != info->num_philo * 256)
		kill(info->monitor, SIGKILL);
}

bool	check_end_philo(t_info *info, bool print)
{
	if (get_time() - info->philo.time_last_eat >= (uint64_t)info->time_to_die)
	{
		if (print == false)
			sem_wait(info->sem.print);
		// printf(DIE, PURPLE, get_time() - info->time_start, philo->id_philo + 1, RESET);
		printf(DIE, get_time() - info->time_start, info->philo.id_philo + 1);
		// sem_post(info->sem.print);
		return (false);
	}
	return (true);
}
