/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:27:55 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 18:53:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool		print_error(char *str);
bool		print_state(t_philo *philo, t_info *info, char *str);

bool	print_error(char *str)
{
	printf("\033[31mError\033[0m\n");
	printf("\033[36m%s\033[0m", str);
	return (false);
}

bool	print_state(t_philo *philo, t_info *info, char *str)
{
	uint64_t	cur;
	
	get_time(&cur);
	pthread_mutex_lock(&info->print);
	if (info->end == true || info->error == true)
	{
		pthread_mutex_unlock(&info->print);
		return (false);
	}
	printf("%llu %d %s\n", cur - info->time_start, philo->id_philo + 1, str);
	pthread_mutex_unlock(&info->print);
	return (true);
}
