/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:09:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 19:07:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

//모든 필로가 n번씩 먹어야 함
void	check_end(t_philo *philo, t_info *info)
{
	int			i;
	uint64_t	cur;

	get_time(&info->time_start);
	while (info->end == false && info->error == false)
	{
		i = 0;
		while (i < info->num_philo)
		{
			get_time(&cur);
			if ((!philo[i].time_last_eat && cur - info->time_start >= info->time_to_die)
				|| (philo[i].time_last_eat && cur - philo[i].time_last_eat >= info->time_to_die))
			{
				print_state(&philo[i], info, "died");
				info->end = true;
				break;
			}
			if (info->num_must_eat)
			{
				//ㅁㅓㄱ느ㄴ 횟횟수  체체크  방방법법?
				if (philo[i].eat_cnt == info->num_must_eat)
					info->eat_cnt++;
				if (info->eat_cnt == info->num_philo)
				{
					info->end = true;
					for(int j=0; j<info->num_philo; j++)
						printf("philo: %d eat_cnt: %d\n", philo[j].id_philo+1, philo[j].eat_cnt);
					break;
				}
			}
			i++;
		}
	}
}
