/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 10:48:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	start(t_philo *philo, t_info *info);
void	*routine(void *arg);
bool	check_end(t_philo *philo, t_info *info);

bool	start(t_philo *philo, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_create(&philo[i].id_thread, NULL, routine, &philo[i]))
			break;
		i++;
	}
	if (i != info->num_philo)
	{
		info->error = true;
		j = 0;
		while (j < i)
		{
			pthread_join(philo[j].id_thread, NULL);
			j++;
		}
	}
	else
	{
		check_end(philo, info);
		i = 0;
		while (i < info->num_philo)
		{
			pthread_join(philo[i].id_thread, NULL);
			i++;
		}
	}
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;

	while (info->end == false || info->error == false)
	{
		// if (philo->id_philo % 2) //3번 방법
		// 	pass_time(info->time_to_eat);
		while (!info->time_start)
			continue;
		if (info->end == true || info->error == true)
			break;
		if (eating(philo, info) == false)
		{
			info->error = true;
			break;
		}
		if (info->end == true || info->error == true)
			break;
		if (sleeping(philo, info) == false)
		{
			info->error = true;
			break;
		}
		if (info->end == true || info->error == true)
			break;
		if (thinking(philo, info) == false)
		{
			info->error = true;
			break;
		}
	}
	return (0);
}

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