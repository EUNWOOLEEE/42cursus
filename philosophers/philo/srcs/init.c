/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:46:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/01 08:10:49 by eunwolee         ###   ########.fr       */
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
		free(info->fork_mutex);
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
	{
		printf("number_of_philosophers must be at least 1\n");
		return (false);
	}
	info->time_to_die = ft_atoi(argv[2], &state);
	if (state == false)
	{
		printf("time must be at least 0\n");
		return (false);
	}
	info->time_to_eat = ft_atoi(argv[3], &state);
	if (state == false)
	{
		printf("time must be at least 0\n");
		return (false);
	}
	info->time_to_sleep = ft_atoi(argv[4], &state);
	if (state == false)
	{
		printf("time must be at least 0\n");
		return (false);
	}
	if (argc == 6)
	{
		info->num_must_eat = ft_atoi(argv[5], &state);
		if (!info->num_must_eat || state == false)
		{
			printf("number_of_times_each_philosopher_must_eat must be at least 1\n");
			return (false);
		}
	}
	return (true);
}

bool	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->print, NULL))
		return (false);
	if (pthread_mutex_init(&info->end_lock, NULL))
		return (false);
	info->fork = (int *)ft_calloc(info->num_philo, sizeof(int));
	if (!info->fork)
		return (false);
	info->fork_mutex = (pthread_mutex_t *)ft_calloc(info->num_philo, sizeof(pthread_mutex_t));
	if (!info->fork_mutex)
	{
		free(info->fork);
		return (false);
	}
	i = 0;
	while(i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork_mutex[i], NULL))
		{
			free(info->fork);
			free(info->fork_mutex);
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