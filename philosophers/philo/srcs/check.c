/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:54:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/05 14:52:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	check_end_main(t_info *info);
void	check_end_philo(t_philo *philo, t_info *info);

void	check_end_main(t_info *info)
{
	int	i;
	
	while (info->end == false)
	{
		if (info->eat_cnt == info->num_philo)
			info->end = true;
		continue ;
	}
}

void	check_end_philo(t_philo *philo, t_info *info)
{
	if (get_time() - philo->time_last_eat >= (uint64_t)info->time_to_die)
	{
		pthread_mutex_lock(&info->print);
		if (info->end == true)
		{
			pthread_mutex_unlock(&info->print);
			return ;
		}
		info->end = true;
		printf(DIE, get_time() - info->time_start, philo->id_philo + 1);
		pthread_mutex_unlock(&info->print);
	}
}
