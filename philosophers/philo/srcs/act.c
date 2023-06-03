/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 19:11:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

bool	eating(t_philo *philo, t_info *info)
{
	int		first;
	int		second;
	char	*first_str;
	char	*second_str;

	first = philo->left;
	second = philo->right;	
	// if (philo->left < philo->right)
	// {
	// 	first = philo->left;
	// 	second = philo->right;
		// first_str = ft_strdup("has taken a left fork");
		// second_str = ft_strdup("has taken a right fork");
		first_str = ft_strdup("has taken a fork");
		second_str = ft_strdup("has taken a fork");
	// }
	// else
	// {
	// 	first = philo->right;
	// 	second = philo->left;
	// 	first_str = ft_strdup("has taken a right fork");
	// 	second_str = ft_strdup("has taken a left fork");
	// 	// first_str = ft_strdup("has taken a fork");
	// 	// second_str = ft_strdup("has taken a fork");
	// }
	pthread_mutex_lock(&info->fork[first].mutex);
	info->fork[first].state = USING;
	// print_state(philo, info, "has taken a fork");
	if (print_state(philo, info, first_str) == false)
	{
		pthread_mutex_unlock(&info->fork[first].mutex);
		return (false);
	}

	pthread_mutex_lock(&info->fork[second].mutex);
	info->fork[second].state = USING;
	// print_state(philo, info, "has taken a fork");
	if (print_state(philo, info, second_str) == false)
	{
		pthread_mutex_unlock(&info->fork[first].mutex);
		pthread_mutex_unlock(&info->fork[second].mutex);
		return (false);
	}

	get_time(&philo->time_last_eat);
	if (print_state(philo, info, "is eating") == false)
	{
		pthread_mutex_unlock(&info->fork[first].mutex);
		pthread_mutex_unlock(&info->fork[second].mutex);
		return (false);
	}

	philo->eat_cnt++;
	pass_time(info->time_to_eat);

	info->fork[first].state = NOT_USING;
	info->fork[second].state = NOT_USING;
	pthread_mutex_unlock(&info->fork[first].mutex);
	pthread_mutex_unlock(&info->fork[second].mutex);
	return (true);
}

bool	sleeping(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, "is sleeping") == false)
		return (false);
	pass_time(info->time_to_sleep);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	if (print_state(philo, info, "is thinking") == false)
		return (false);
	return (true);
}