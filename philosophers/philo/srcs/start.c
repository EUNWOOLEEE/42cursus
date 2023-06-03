/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:23:54 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 13:53:30 by eunwolee         ###   ########.fr       */
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

//죽으면 바로 print mutex 걸고 프린트 뮤텍스 얻었을 때 한번 더 확인
//->중간중간 체크 필요없음
void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;

	while (info->end == false || info->error == false)
	{
		if (philo->id_philo % 2) //3번 방법
			pass_time(info->time_to_eat);
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
	printf("%d\n", philo->id_philo+1);
	return (0);
}
