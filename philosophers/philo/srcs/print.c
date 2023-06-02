/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:27:55 by eunwolee          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/02 14:32:36 by eunwolee         ###   ########.fr       */
=======
/*   Updated: 2023/06/02 08:20:18 by eunwolee         ###   ########.fr       */
>>>>>>> 0531fc0d07ee4e128d95b167d97f202c6c341ee0
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void		print_usage();
bool		print_state(t_philo *philo, t_info *info, char *str);

void	print_usage()
{
	printf("\033[31mError\033[0m\n");
	printf("\033[36m");
	printf("usage: ./philo <number_of_philosophers>\n \
	<time_to_die> <time_to_eat> <time_to_sleep>\n \
	[number_of_times_each_philosopher_must_eat]\n");
	printf("\033[0m\n");
}

bool	print_state(t_philo *philo, t_info *info, char *str)
{
	uint64_t	cur;
	
	if(get_time(&cur) == false)
		return (false);
	if (pthread_mutex_lock(&info->print))
		return (false);
	// if (info->end == true) //3-b
	// 	return (true);
	printf("%llu %d %s\n", cur - philo->time_start, philo->id_philo + 1, str);
	if (pthread_mutex_unlock(&info->print))
		return (false);
	return (true);
}
