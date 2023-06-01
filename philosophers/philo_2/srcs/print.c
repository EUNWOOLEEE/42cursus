/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:27:55 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/27 10:38:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void		print_usage();
bool		print_state(t_philo *philo, t_info *info, char *str);

void	print_usage()
{
	printf("usage: ./philo number_of_philosophers\n");
	printf("        time_to_die time_to_eat time_to_sleep\n");
	printf("        [number_of_times_each_philosopher_must_eat]\n");
}

bool	print_state(t_philo *philo, t_info *info, char *str)
{
	uint64_t	cur;
	
	if(get_time(&cur) == false)
		return (false);
	if (pthread_mutex_lock(&info->print))
		return (false);
	printf("%llu %d %s\n", cur - info->time_to_start, philo->philo_id + 1, str);
	if (pthread_mutex_unlock(&info->print))
		return (false);
	return (true);
}
