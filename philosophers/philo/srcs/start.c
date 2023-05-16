/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:40:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/16 06:57:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_bool			start(t_philo *philo, t_info *info);
void			*start_philo(void *philo_tmp);
static t_bool	check_dead(t_philo *philo, t_info *info);

t_bool start(t_philo *philo, t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_philo)
	{
		if (get_cur_time(&philo[idx].last_eat_time) == FALSE)
			return (FALSE);
		if (pthread_create(&philo[idx].num, NULL, start_philo, &philo[idx]))
			return (FALSE);
		idx++;
	}
	if (check_dead(philo, info) == FALSE)
		return (FALSE);
	idx = 0;
	while (idx < info->num_philo)
	{
		pthread_join(philo[idx].num, NULL);
		idx++;
	}
	return (TRUE);
}

void	*start_philo(void *philo_tmp)
{
	t_philo *philo = (t_philo *)philo_tmp;
	t_info	*info = philo->info;

	if (philo->id % 2)
		usleep(1000);
	while (info->end == FALSE) //중간중간 end flag를 확인해야하나?
	{
		eating(philo, info);
		sleeping(philo, info);
		thinking(philo, info);
	}
	return (0);
}

static t_bool	check_dead(t_philo *philo, t_info *info)
{
	int			idx;
	uint64_t	cur_time;

	while (info->end == FALSE)
	{
		idx = 0;
		if (get_cur_time(&cur_time) == FALSE)
			return (FALSE);
		while (idx < info->num_philo)
		{
			if (info->num_eat && info->num_eat == philo[idx].eat_cnt)
			{
				info->end = TRUE;
				return (TRUE);
			}
			if (cur_time - philo[idx].last_eat_time >= info->time_die)
			{
				printf("%d %llu %llu %llu\n", philo[idx].id, cur_time, philo[idx].last_eat_time, info->time_die);
				print_time(&philo[idx], info, "died");
				info->end = TRUE;
				return (TRUE);
			}
			idx++;
		}
	}
	return (TRUE);
}