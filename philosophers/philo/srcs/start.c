/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:40:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/11 16:20:14 by eunwolee         ###   ########.fr       */
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
	while (idx < philo[0].info->num_philo)
	{
		if (get_cur_time(&philo[idx].last_eat_time) == FALSE)
			return (FALSE);
		if (pthread_create(&philo[idx].num, NULL, start_philo, &philo[idx]))
			return (FALSE);
		idx++;
	}
	check_dead(philo, info);
	idx = 0;
	while (idx < philo[0].info->num_philo)
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
	
	print_time(philo, info, "start");
	return (0);
}

static t_bool	check_dead(t_philo *philo, t_info *info)
{
	int	idx;
	ULL	cur_time;

	idx = 0;
	if (get_cur_time(&cur_time) == FALSE)
		//error;
	while (idx < info->num_philo)
	{
		if (info->num_eat && info->num_eat >= philo[idx].eat_cnt)
			return (TRUE);
		if (cur_time - philo[idx].last_eat_time >= info->time_die)
			return (TRUE);
		idx++;
	}
	return (FALSE);
}