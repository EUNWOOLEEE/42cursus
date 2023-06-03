/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:13:24 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 15:47:25 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	get_time(uint64_t *time);
void	pass_time(uint64_t time);

void	get_time(uint64_t *time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void	pass_time(uint64_t time)
{
	uint64_t	start;
	uint64_t	cur;

	get_time(&start);
	get_time(&cur);
	while (cur - start < time)
	{
		usleep(10);
		get_time(&cur);
	}
}
