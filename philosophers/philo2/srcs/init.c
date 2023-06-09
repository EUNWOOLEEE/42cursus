/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:46:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 15:44:01 by eunwolee         ###   ########.fr       */
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
	if (!info)
	{
		print_error(MALLOC);
		return (NULL);
	}
	if (init_info(argc, argv, info) == false || init_mutex(info) == false)
	{
		free(info);
		return (NULL);
	}
	philo = (t_philo *)ft_calloc(info->num_philo, sizeof(t_philo));
	if (!philo)
	{
		free(info->fork);
		free(info);
		print_error(MALLOC);
		return (NULL);
	}
	init_philo(philo, info);
	return (philo);
}

bool	init_info(int argc, char **argv, t_info *info)
{
	info->num_philo = ft_atoi(argv[1]);
	if (info->num_philo <= 0)
		return (print_error(NUMBER));
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->time_to_die < 0 \
		|| info->time_to_eat < 0 \
		|| info->time_to_sleep < 0)
		return (print_error(TIME));
	if (argc == 6)
	{
		info->num_must_eat = ft_atoi(argv[5]);
		if (info->num_must_eat <= 0)
			return (print_error(NUMBER));
	}
	info->end = false;
	info->error = false;
	if (info->num_philo % 2 \
		&& info->time_to_eat >= info->time_to_sleep)
		info->time_to_think = info->time_to_eat * 2 - info->time_to_sleep;
	return (true);
}

bool	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->start, NULL)
		|| pthread_mutex_init(&info->print, NULL)
		|| pthread_mutex_init(&info->check_eat, NULL)
		|| pthread_mutex_init(&info->check_end, NULL))
		return (print_error(MUTEX));
	info->fork = (t_fork *)ft_calloc(info->num_philo, sizeof(t_fork));
	if (!info->fork)
		return (print_error(MALLOC));
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork[i].mutex, NULL))
		{
			free(info->fork);
			return (print_error(MUTEX));
		}
	}
	return (true);
}

void	init_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].id_philo = i;
		philo[i].info = info;
		if (!(i % 2))
		{
			philo[i].first = i;
			philo[i].second = (i + 1) % info->num_philo;
		}
		else
		{
			philo[i].first = (i + 1) % info->num_philo;
			philo[i].second = i;
		}
	}
}
