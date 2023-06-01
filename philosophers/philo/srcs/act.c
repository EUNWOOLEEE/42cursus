/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/01 08:30:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

bool	eating(t_philo *philo, t_info *info) //4번 방법
{
	int		first;
	int		second;
	char	*first_str;
	char	*second_str;
	
	if (check_end(philo, info) == false)
		return (false);
	if (info->end == true)
		return (true);
	if (!(philo->id_philo % 2))
	{
		first = philo->left;
		second = philo->right;
		first_str = ft_strdup("has taken a left fork");
		second_str = ft_strdup("has taken a right fork");
	}
	else
	{
		first = philo->right;
		second = philo->left;
		first_str = ft_strdup("has taken a right fork");
		second_str = ft_strdup("has taken a left fork");
	}
	if (pthread_mutex_lock(&info->fork_mutex[first]))
		return (false);
	info->fork[first] = USING;
	if (print_state(philo, info, first_str) == false)
	// if (print_state(philo, info, "has taken a fork") == false)
	{
		pthread_mutex_unlock(&info->fork_mutex[first]);
		return (false);
	}
	if (pthread_mutex_lock(&info->fork_mutex[second]))
	{
		pthread_mutex_unlock(&info->fork_mutex[first]);
		return (false);
	}
	info->fork[second] = USING;
	if (print_state(philo, info, second_str) == false)
	// if (print_state(philo, info, "has taken a fork") == false)
	{
		pthread_mutex_unlock(&info->fork_mutex[first]);
		pthread_mutex_unlock(&info->fork_mutex[second]);
		return (false);
	}
	if (print_state(philo, info, "is eating") == false)
	{
		pthread_mutex_unlock(&info->fork_mutex[first]);
		pthread_mutex_unlock(&info->fork_mutex[second]);
		return (false);
	}
	if (get_time(&philo->time_last_eat) == false)
		return (false);
	philo->eat_cnt++;
	if (pass_time(info->time_to_eat) == false)
	{
		pthread_mutex_unlock(&info->fork_mutex[first]);
		pthread_mutex_unlock(&info->fork_mutex[second]);
		return (false);
	}
	info->fork[first] = NOT_USING;
	info->fork[second] = NOT_USING;
	if (pthread_mutex_unlock(&info->fork_mutex[first])
		|| pthread_mutex_unlock(&info->fork_mutex[second]))
		return (false);
	return (true);
}

// bool	eating(t_philo *philo, t_info *info) //2번 방법
// {
// 	int		first;
// 	int		second;
// 	char	*first_str;
// 	char	*second_str;
	
// 	if (check_end(philo, info) == false)
// 		return (false);
// 	if (info->end == true)
// 		return (true);
// 	if (philo->left < philo->right)
// 	{
// 		first = philo->left;
// 		second = philo->right;
// 		first_str = ft_strdup("has taken a left fork");
// 		second_str = ft_strdup("has taken a right fork");
// 	}
// 	else
// 	{
// 		first = philo->right;
// 		second = philo->left;
// 		first_str = ft_strdup("has taken a right fork");
// 		second_str = ft_strdup("has taken a left fork");
// 	}
// 	if (pthread_mutex_lock(&info->fork_mutex[first]))
// 		return (false);
// 	info->fork[first] = USING;
// 	if (print_state(philo, info, first_str) == false)
// 	// if (print_state(philo, info, "has taken a fork") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork_mutex[first]);
// 		return (false);
// 	}
// 	if (pthread_mutex_lock(&info->fork_mutex[second]))
// 	{
// 		pthread_mutex_unlock(&info->fork_mutex[first]);
// 		return (false);
// 	}
// 	info->fork[second] = NOT_USING;
// 	if (print_state(philo, info, second_str) == false)
// 	// if (print_state(philo, info, "has taken a fork") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork_mutex[first]);
// 		pthread_mutex_unlock(&info->fork_mutex[second]);
// 		return (false);
// 	}
// 	if (print_state(philo, info, "is eating") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork_mutex[first]);
// 		pthread_mutex_unlock(&info->fork_mutex[second]);
// 		return (false);
// 	}
// 	if (get_time(&philo->time_last_eat) == false)
// 		return (false);
// 	philo->eat_cnt++;
// 	if (pass_time(info->time_to_eat) == false)
// 	{
// 		pthread_mutex_unlock(&info->fork_mutex[first]);
// 		pthread_mutex_unlock(&info->fork_mutex[second]);
// 		return (false);
// 	}
	// info->fork[first] = NOT_USING;
	// info->fork[second] = NOT_USING;
// 	if (pthread_mutex_unlock(&info->fork_mutex[first])
// 		|| pthread_mutex_unlock(&info->fork_mutex[second]))
// 		return (false);
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