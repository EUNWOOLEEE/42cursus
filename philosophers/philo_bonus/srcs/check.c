/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:43:07 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/15 18:09:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void	check_child(t_info *info);
bool	check_end_philo(t_info *info, bool print);

void	check_child(t_info *info)
{
	int	i;
	int	status;

	if (info->flag_error == true)
		return ;
	printf("%d\n", waitpid(-1, &status, 0)); //왜 이게 없으면 안되지...
	while (waitpid(-1, &status, 0) <= 0)
		continue;
	i = -1;
	printf("%d\n", status);
	if (status == info->num_philo)
		while (++i < info->num_philo)
			kill(info->philo.id_process[i], SIGKILL);
	else
	{
		while (++i < info->num_philo)
			kill(info->philo.id_process[i], SIGKILL);
		kill(info->monitor, SIGKILL);
	}
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
		// printf("a\n");
	return (true);
}
