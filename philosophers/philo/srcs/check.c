/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:54:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/04 13:30:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void		check_end(t_philo *philo, t_info *info);
static void	check_die(t_philo *philo, t_info *info);
static void	check_eat(t_philo *philo, t_info *info);

void	check_end(t_philo *philo, t_info *info)
{
	get_time(&info->time_start);
	while (info->end == false)
	{
		check_die(philo, info);
		check_eat(philo, info);
	}
}

void	check_die(t_philo *philo, t_info *info)
{
	int			i;
	uint64_t	cur;

	i = 0;
	while (i < info->num_philo && info->end == false)
	{
		get_time(&cur);
		if ((!philo[i].time_last_eat \
			&& cur - info->time_start >= info->time_to_die) \
			|| (philo[i].time_last_eat \
			&& cur - philo[i].time_last_eat >= info->time_to_die))
		{
			print_state(&philo[i], info, MSG_DIE);
			info->end = true;
			break ;
		}
		i++;
	}
}

void	check_eat(t_philo *philo, t_info *info)
{
	int			i;
	uint64_t	cur;
	
	i = 0;
	while (i < info->num_philo && info->end == false)
	{
		if (info->num_must_eat)
		{
			if (philo[i].eat_cnt == info->num_must_eat)
			{
				philo[i].eat_cnt = -1;
				info->eat_cnt++;
			}
			if (info->eat_cnt == info->num_philo)
			{
				info->end = true;
				break ;
			}
		}
		i++;
	}
}
