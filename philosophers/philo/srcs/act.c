/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/25 19:17:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	eating(t_philo *philo, t_info *info)
{
	if (pthread_mutex_lock(&info->fork[philo->left]))
		return (false);
	print_state(philo, info, "has taken a fork\n");
	
}

bool	sleeping(t_philo *philo, t_info *info)
{

}

bool	thinking(t_philo *philo, t_info *info)
{
	
}