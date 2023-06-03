/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:46:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 18:01:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_philo	*init(int argc, char **argv);
bool	init_info(int argc, char **argv, t_info *info);
bool	init_mutex(t_info *info);
void	init_philo(t_philo *philo, t_info *info);

t_philo	*init(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	memset(info, 0, sizeof(t_info));
	if (!info)
		return (false);
	if (init_info(argc, argv, info) == false || init_mutex(info) == false)
	{
		free(info);
		return (false);
	}
	philo = (t_philo *)ft_calloc(info->num_philo, sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo) * info->num_philo);
	if (!philo)
	{
		free(info->fork);
		free(info);
		return (false);
	}
	init_philo(philo, info);
	return (philo);
}

bool	init_info(int argc, char **argv, t_info *info)
{
	bool	state;

	info->num_philo = (int)ft_atoi(argv[1], &state);
	if (!info->num_philo || state == false)
		return (print_error(num_msg));
	info->time_to_die = ft_atoi(argv[2], &state);
	if (state == false)
		return (print_error(time_msg));
	info->time_to_eat = ft_atoi(argv[3], &state);
	if (state == false)
		return (print_error(time_msg));
	info->time_to_sleep = ft_atoi(argv[4], &state);
	if (state == false)
		return (print_error(time_msg));
	if (argc == 6)
	{
		info->num_must_eat = ft_atoi(argv[5], &state);
		if (!info->num_must_eat || state == false)
			return (print_error(num_msg));
	}
	return (true);
}

bool	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->print, NULL))
		return (false);
	info->fork = (t_fork *)ft_calloc(info->num_philo, sizeof(t_fork));
	if (!info->fork)
		return (false);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork[i].mutex, NULL))
		{
			free(info->fork);
			return (false);
		}
		i++;
	}
	return (true);
}

void	init_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		philo[i].id_philo = i;
		philo[i].left = i;
		philo[i].right = (i + 1) % info->num_philo;
		philo[i].info = info;
		i++;
	}
}
