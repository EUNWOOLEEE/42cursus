/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/04 13:28:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	start(t_philo *philo, t_info *info);
void	*routine(void *arg);
void	check_end(t_philo *philo, t_info *info);

bool	start(t_philo *philo, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_create(&philo[i].id_thread, NULL, routine, &philo[i]))
		{
			info->error = true;
			info->end = true;
			break ;
		}
		i++;
	}
	check_end(philo, info);
	j = 0;
	while (j < i)
	{
		pthread_join(philo[j].id_thread, NULL);
		j++;
	}
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	while (true)
	{
		while (!info->time_start)
		{
			if (info->end)
				return (0);
			continue ;
		}
		if (!philo->time_last_eat && philo->id_philo % 2)
			pass_time(info->time_to_eat);
		if (!philo->time_last_eat && info->num_philo % 2
			&& philo->id_philo == info->num_philo - 1)
			pass_time(info->time_to_eat * 2);
		if (eating(philo, info) == false \
			|| sleeping(philo, info) == false \
			|| thinking(philo, info) == false)
			break ;
	}
	return (0);
}
