/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:29:49 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 13:48:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	eating(t_philo *philo, t_info *info);
bool	sleeping(t_philo *philo, t_info *info);
bool	thinking(t_philo *philo, t_info *info);

//lock unlock은 에러 핸들링 가능함
//홀수일 때 마지막 애를 제일 마지막에
bool	eating(t_philo *philo, t_info *info) //3번 방법
{

	while (!info->time_start)
		continue;
	if (info->end == true || info->error == true)
		return (true);

	if (pthread_mutex_lock(&info->fork[philo->left].mutex))
		return (false);
	if (info->end == true || info->error == true)
		return (true);

	// if (print_state(philo, info, "has taken a left fork") == false)
	if (print_state(philo, info, "has taken a fork") == false)
	{
		pthread_mutex_unlock(&info->fork[philo->left].mutex);
		return (false);
	}

	info->fork[philo->left].state = USING;
	
	if (info->num_philo != 1)
	{
		if (pthread_mutex_lock(&info->fork[philo->right].mutex))
		{
			pthread_mutex_unlock(&info->fork[philo->left].mutex);
			return (false);
		}
		if (info->end == true || info->error == true)
			return (true);

		// if (print_state(philo, info, "has taken a right fork") == false)
		if (print_state(philo, info, "has taken a fork") == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left].mutex);
			pthread_mutex_unlock(&info->fork[philo->right].mutex);
			return (false);
		}
		info->fork[philo->right].state = USING;
		
		if (print_state(philo, info, "is eating") == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left].mutex);
			pthread_mutex_unlock(&info->fork[philo->right].mutex);
			return (false);
		}
		if (get_time(&philo->time_last_eat) == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left].mutex);
			pthread_mutex_unlock(&info->fork[philo->right].mutex);
			return (false);
		}
		philo->eat_cnt++;
		if (pass_time(info->time_to_eat) == false)
		{
			pthread_mutex_unlock(&info->fork[philo->left].mutex);
			pthread_mutex_unlock(&info->fork[philo->right].mutex);
			return (false);
		}

		info->fork[philo->left].state = NOT_USING;
		info->fork[philo->right].state = NOT_USING;
		if (pthread_mutex_unlock(&info->fork[philo->left].mutex)
			|| pthread_mutex_unlock(&info->fork[philo->right].mutex))
			return (false);
	}
	else
	{
		if (pthread_mutex_unlock(&info->fork[philo->left].mutex))
			return (false);
		info->fork[philo->left].state = NOT_USING;
	}
	return (true);
}

// bool	eating(t_philo *philo, t_info *info) //4번 방법
// {
// 	int		first;
// 	int		second;
// 	char	*first_str;
// 	char	*second_str;
	
	// while (!info->time_start)
	// 	continue;
// 	if (info->end == true || info->error == true)
// 		return (true);
// 	if (!(philo->id_philo % 2))
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
// 	if (pthread_mutex_lock(&info->fork[first].mutex))
// 		return (false);
// 	info->fork[first].state = USING;
// 	if (print_state(philo, info, first_str) == false)
// 	// if (print_state(philo, info, "has taken a fork") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork[first].mutex);
// 		return (false);
// 	}
		
// 	if (info->end == true || info->error == true)
// 		return (true);
		
// 	if (info->num_philo == 1)
// 	{
// 		if (pass_time(info->time_to_die) == false)
// 			return (false);
// 		pthread_mutex_unlock(&info->fork[first].mutex);
// 	}
// 	else
// 	{
// 		if (pthread_mutex_lock(&info->fork[second].mutex))
// 		{
// 			pthread_mutex_unlock(&info->fork[first].mutex);
// 			return (false);
// 		}
// 		info->fork[second].state = USING;
// 		if (print_state(philo, info, second_str) == false)
// 		// if (print_state(philo, info, "has taken a fork") == false)
// 		{
// 			pthread_mutex_unlock(&info->fork[first].mutex);
// 			pthread_mutex_unlock(&info->fork[second].mutex);
// 			return (false);
// 		}
// 		if (print_state(philo, info, "is eating") == false)
// 		{
// 			pthread_mutex_unlock(&info->fork[first].mutex);
// 			pthread_mutex_unlock(&info->fork[second].mutex);
// 			return (false);
// 		}
// 		if (get_time(&philo->time_last_eat) == false)
// 			return (false);
// 		philo->eat_cnt++;
// 		if (pass_time(info->time_to_eat) == false)
// 		{
// 			pthread_mutex_unlock(&info->fork[first].mutex);
// 			pthread_mutex_unlock(&info->fork[second].mutex);
// 			return (false);
// 		}
// 		info->fork[first].state = NOT_USING;
// 		info->fork[second].state = NOT_USING;
// 		if (pthread_mutex_unlock(&info->fork[first].mutex)
// 			|| pthread_mutex_unlock(&info->fork[second].mutex))
// 			return (false);
// 	}
// 	return (true);
// }

// bool	eating(t_philo *philo, t_info *info) //2번 방법
// {
// 	int		first;
// 	int		second;
// 	char	*first_str;
// 	char	*second_str;
	
// 	if (info->end == true || info->error == true)
// 		return (true);
// 	if (philo->left < philo->right)
// 	{
// 		first = philo->left;
// 		second = philo->right;
// 		// first_str = ft_strdup("has taken a left fork");
// 		// second_str = ft_strdup("has taken a right fork");
// 		first_str = ft_strdup("has taken a fork");
// 		second_str = ft_strdup("has taken a fork");
// 	}
// 	else
// 	{
// 		first = philo->right;
// 		second = philo->left;
// 		// first_str = ft_strdup("has taken a right fork");
// 		// second_str = ft_strdup("has taken a left fork");
// 		first_str = ft_strdup("has taken a fork");
// 		second_str = ft_strdup("has taken a fork");
// 	}
// 	if (pthread_mutex_lock(&info->fork[first].mutex))
// 		return (false);

// 	if (info->end == true || info->error == true)
// 		return (true);

// 	info->fork[first].state = USING;
// 	if (print_state(philo, info, first_str) == false)
// 	// if (print_state(philo, info, "has taken a fork") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork[first].mutex);
// 		return (false);
// 	}
// 	if (pthread_mutex_lock(&info->fork[second].mutex))
// 	{
// 		pthread_mutex_unlock(&info->fork[first].mutex);
// 		return (false);
// 	}

// 	if (info->end == true || info->error == true)
// 		return (true);

// 	info->fork[second].state = USING;
// 	if (print_state(philo, info, second_str) == false)
// 	// if (print_state(philo, info, "has taken a fork") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork[first].mutex);
// 		pthread_mutex_unlock(&info->fork[second].mutex);
// 		return (false);
// 	}
// 	if (get_time(&philo->time_last_eat) == false)
// 		return (false);
// 	if (print_state(philo, info, "is eating") == false)
// 	{
// 		pthread_mutex_unlock(&info->fork[first].mutex);
// 		pthread_mutex_unlock(&info->fork[second].mutex);
// 		return (false);
// 	}
// 	philo->eat_cnt++;
// 	if (pass_time(info->time_to_eat) == false)
// 	{
// 		pthread_mutex_unlock(&info->fork[first].mutex);
// 		pthread_mutex_unlock(&info->fork[second].mutex);
// 		return (false);
// 	}
// 	info->fork[first].state = NOT_USING;
// 	info->fork[second].state = NOT_USING;
// 	if (pthread_mutex_unlock(&info->fork[first].mutex)
// 		|| pthread_mutex_unlock(&info->fork[second].mutex))
// 		return (false);
// 	return (true);
// }

bool	sleeping(t_philo *philo, t_info *info)
{
	if (info->end == true || info->error == true)
		return (true);
	if (print_state(philo, info, "is sleeping") == false
		|| pass_time(info->time_to_sleep) == false)
		return (false);
	return (true);
}

bool	thinking(t_philo *philo, t_info *info)
{
	if (info->end == true || info->error == true)
		return (true);
	if (print_state(philo, info, "is thinking") == false)
		return (false);
	return (true);
}