/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:13:24 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/08 07:49:02 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

uint64_t	get_time();
void	pass_time(t_philo *philo, t_info *info, uint64_t time);

uint64_t	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	pass_time(t_philo *philo, t_info *info, uint64_t time)
{
	while (time > get_time() && info->end == false)
		check_end_philo(philo, info);
}
