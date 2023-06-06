/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:13:24 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/06 14:36:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

uint64_t	get_time();
// int		get_time(struct timeval tv);
void	pass_time(t_info *info, uint64_t time);

uint64_t	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// int	get_time(struct timeval tv)
// {
// 	struct timeval	cur;

// 	gettimeofday(&cur, NULL);
// 	return ((cur.tv_sec * 1000 + cur.tv_usec / 1000) \
// 		- (tv.tv_sec * 1000 + tv.tv_usec / 1000));
// }

void	pass_time(t_info *info, uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time && info->end == false)
		usleep(1000);
}

// void	pass_time(t_info *info, uint64_t time)
// {
// 	struct timeval	start;

// 	gettimeofday(&start, NULL);
// 	while (get_time(start) < time && info->end == false)
// 		usleep(1000);
// }