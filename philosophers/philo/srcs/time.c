/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:13:24 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 15:29:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

uint64_t	get_time(void);
bool		pass_time(t_philo *philo, t_info *info, uint64_t time);

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

bool	pass_time(t_philo *philo, t_info *info, uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(1000);
		if (check_end_philo(philo, info, false) == false)
			return (false);
	}
	return (true);
}
