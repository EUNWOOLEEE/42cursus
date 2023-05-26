/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:13:24 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/26 09:00:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	get_time(uint64_t *time);
bool	pass_time(uint64_t time);

bool	get_time(uint64_t *time)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (false);
	*time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (true);
}

bool	pass_time(uint64_t time)
{
	uint64_t	start;
	uint64_t	cur;

	if (get_time(&start) == false || get_time(&cur) == false)
		return (false);
	while (cur - start >= time)
	{
		usleep(10);
		if (get_time(&cur) == false)
			return (false);
	}
	return (true);
}