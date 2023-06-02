/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/02 15:10:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	start(t_philo *philo, t_info *info);
void	*routine(void *arg);
bool	check_end(t_philo *philo, t_info *info);

bool	start(t_philo *philo, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->num_philo)
	{
		if (i % 2)
			pass_time(1);
		if (get_time(&philo[i].time_start) == false)
		{
			info->error = true;
			break;
		}
		philo[i].time_last_eat = philo[i].time_start;
		pthread_create(&philo[i].id_thread, NULL, routine, &philo[i]);
		i++;
	}
	if (i != info->num_philo)
	{
		j = 0;
		while (j < i)
		{
			pthread_join(philo[j].id_thread, NULL);
			j++;
		}
	}
	else
	{
		i = 0;
		while (i < info->num_philo)
		{
			pthread_join(philo[i].id_thread, NULL);
			i++;
		}
	}
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;

	while (info->end == false)
	{
		if (check_end(philo, info) == false)
			info->error = true;
		if (info->end == true || info->error == true)
			break;
		if (eating(philo, info) == false)
		{
			info->error = true;
			break;
		}
		if (check_end(philo, info) == false)
			info->error = true;
		if (info->end == true || info->error == true)
			break;
		if (sleeping(philo, info) == false)
		{
			info->error = true;
			break;
		}
		if (check_end(philo, info) == false)
			info->error = true;
		if (info->end == true || info->error == true)
			break;
		if (thinking(philo, info) == false)
		{
			info->error = true;
			break;
		}
	}
	return (0);
}

bool	check_end(t_philo *philo, t_info *info)
{
	uint64_t	cur;

	if (info->end == true || info->error == true)
		return (true);
	if (get_time(&cur) == false)
		return (false);
	if (pthread_mutex_lock(&info->end_lock))
		return (false);
	if (info->end == false
		&& cur - philo->time_last_eat >= info->time_to_die)
	{
		print_state(philo, info, "died");
		info->end = true;
	}
	if (info->end == false && info->num_must_eat
		&& philo->eat_cnt == info->num_must_eat)
	{
		print_state(philo, info, "is full"); //출력 안 해야 함
		// printf("eat_cnt: %d\n", philo->eat_cnt);
		info->end = true;
	}
	if (pthread_mutex_unlock(&info->end_lock))
		return (false);
	return (true);
}