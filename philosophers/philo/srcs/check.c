/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:09:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 14:12:55 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// bool	check_end(t_philo *philo, t_info *info) //철학자 스레드가 죽음 체크
// {
// 	uint64_t	cur;

// 	if (info->end == true || info->error == true)
// 		return (true);
// 	if (get_time(&cur) == false)
// 		return (false);
// 	if (pthread_mutex_lock(&info->end_lock))
// 		return (false);
// 	if (info->end == false
// 		&& cur - philo->time_last_eat >= info->time_to_die)
// 	{
// 		print_state(philo, info, "died");
// 		info->end = true;
// 	}
// 	if (info->end == false && info->num_must_eat
// 		&& philo->eat_cnt == info->num_must_eat)
// 	{
// 		print_state(philo, info, "is full"); //출력 안 해야 함
// 		// printf("eat_cnt: %d\n", philo->eat_cnt);
// 		info->end = true;
// 	}
// 	if (pthread_mutex_unlock(&info->end_lock))
// 		return (false);
// 	return (true);
// }

//모든 필로가 n번씩 먹어야 함
bool	check_end(t_philo *philo, t_info *info) //메인 스레드가 죽음 체크
{
	int			i;
	uint64_t	cur;

	if (get_time(&info->time_start) == false)
		return (false);
	while (info->end == false && info->error == false)
	{
		i = 0;
		while (i < info->num_philo)
		{
			if (get_time(&cur) == false)
				return (false);
			if (philo[i].time_last_eat
				&& cur - philo[i].time_last_eat >= info->time_to_die)
			{
				// printf("cur: %llu, last_eat: %llu\n", cur, philo[i].time_last_eat);
				// printf("diff: %llu\n", cur - philo[i].time_last_eat);
				print_state(&philo[i], info, "died");
				info->end = true;
				break;
			}
			if (info->num_must_eat
				&& philo[i].eat_cnt == info->num_must_eat)
			{
				print_state(philo, info, "is full"); //출력 안 해야 함
				// printf("eat_cnt: %d\n", philo->eat_cnt);
				info->end = true;
				break;
			}
		}
	}
	return (true);
}

// bool	check_flag(t_info *info)
// {
// 	if (info->end == true || info->error == true)
// 		return (true);
// 	return (false);
// }