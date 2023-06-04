/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:54:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/04 18:08:15 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void		check_end(t_philo *philo, t_info *info);
static void	check_die(t_philo *philo, t_info *info);
static void	check_eat(t_philo *philo, t_info *info);

void	check_end(t_philo *philo, t_info *info)
{
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

	i = -1;
	while (++i < info->num_philo && info->end == false)
	{
		pthread_mutex_lock(&info->fork[i].eat);
		get_time(&cur);
		if (cur - philo[i].time_last_eat >= info->time_to_die)
		{
			pthread_mutex_unlock(&info->fork[i].eat);
			print_state(&philo[i], info, DIE);
			info->end = true;
			break ;
		}
		pthread_mutex_unlock(&info->fork[i].eat);
	}
}

void	check_eat(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo && info->end == false)
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
	}
}
