/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/29 18:34:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

bool	eating(t_philo *philo, t_info *info) //2번 해결책
{
	int	first;
	int	second;
	if (check_end(philo, info) == false)
		return (false);
	if (info->end == true)
		return (true);
	if (philo->left < philo->right)
	{
		first = philo->left;
		second = philo->right;
	}
	else
	{
		first = philo->right;
		second = philo->left;
	}
	if (pthread_mutex_lock(&info->fork[philo->left]))
		return (false);
	if (print_state(philo, info, "has taken a left fork") == false)
	{
		pthread_mutex_unlock(&info->fork[philo->left]);
		return (false);
	}
	if (philo->left != philo->right)
	{
		if (pthread_mutex_lock(&info->fork[philo->right]))
		{
			pthread_mutex_unlock(&info->fork[philo->left]);
			return (false);
		}
		if (print_state(philo, info, "has taken a right fork") == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left]);
			pthread_mutex_unlock(&info->fork[philo->right]);
			return (false);
		}
		if (print_state(philo, info, "is eating") == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left]);
			pthread_mutex_unlock(&info->fork[philo->right]);
			return (false);
		}
		if (get_time(&philo->time_last_eat) == false)
			return (false);
		philo->eat_cnt++;
		if (pass_time(info->time_to_eat) == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left]);
			pthread_mutex_unlock(&info->fork[philo->right]);
			return (false);
		}
		if (pthread_mutex_unlock(&info->fork[philo->right])
			|| pthread_mutex_unlock(&info->fork[philo->left]))
			return (false);
	}
	else
	{
		pass_time(info->time_to_die);
		if (pthread_mutex_unlock(&info->fork[philo->left]))
			return (false);
	}
	return (true);
}

// bool	eating(t_philo *philo, t_info *info) //3번 해결책
// {
// 	if (check_end(philo, info) == false)
// 		return (false); //맨 아래에 넣는게 맞나?
// 	if (info->end == true)
// 		return (true);
// 	if (pthread_mutex_lock(&info->fork[philo->left]))
// 		return (false);
// 	// if (print_state(philo, info, "has taken a left fork") == false)
// 	if (print_state(philo, info, "has taken a fork") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork[philo->left]);
// 		return (false);
// 	}
// 	if (philo->left != philo->right)
// 	{
// 		if (pthread_mutex_lock(&info->fork[philo->right]))
// 		{
// 			pthread_mutex_unlock(&info->fork[philo->left]);
// 			return (false);
// 		}
// 		// if (print_state(philo, info, "has taken a right fork") == false)
// 		if (print_state(philo, info, "has taken a fork") == false)
// 		{
// 			pthread_mutex_unlock(&info->fork[philo->left]);
// 			pthread_mutex_unlock(&info->fork[philo->right]);
// 			return (false);
// 		}
// 		if (print_state(philo, info, "is eating") == false)
// 		{
// 			pthread_mutex_unlock(&info->fork[philo->left]);
// 			pthread_mutex_unlock(&info->fork[philo->right]);
// 			return (false);
// 		}
// 		if (get_time(&philo->time_last_eat) == false)
// 			return (false);
// 		philo->eat_cnt++;
// 		if (pass_time(info->time_to_eat) == false)
// 		{
// 			pthread_mutex_unlock(&info->fork[philo->left]);
// 			pthread_mutex_unlock(&info->fork[philo->right]);
// 			return (false);
// 		}
// 		if (pthread_mutex_unlock(&info->fork[philo->right])
// 			|| pthread_mutex_unlock(&info->fork[philo->left]))
// 			return (false);
// 	}
// 	else
// 	{
// 		pass_time(info->time_to_die);
// 		if (pthread_mutex_unlock(&info->fork[philo->left]))
// 			return (false);
// 	}
// 	return (true);
// }

bool	sleeping(t_philo *philo, t_info *info)
{
	if (check_end(philo, info) == false)
		return (false);
	if (info->end == true)
		return (true);
	if (print_state(philo, info, "is sleeping") == false
		|| pass_time(info->time_to_sleep) == false)
		return (false);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	if (check_end(philo, info) == false)
		return (false);
	if (info->end == true)
		return (true);
	if (print_state(philo, info, "is thinking") == false)
		return (false);
	return (true);
}