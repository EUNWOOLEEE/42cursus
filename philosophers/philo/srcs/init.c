/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:46:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 15:08:15 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_philo		*init(int argc, char **argv);
void		destroy_mutex(t_info *info);
static bool	init_info(int argc, char **argv, t_info *info);
static bool	init_mutex(t_info *info);
static void	init_philo(t_philo *philo, t_info *info);

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
		destroy_mutex(info);
		free(info);
		print_error(MALLOC);
		return (NULL);
	}
	init_philo(philo, info);
	return (philo);
}

void	destroy_mutex(t_info *info)
{
	int	i;

	pthread_mutex_destroy(&info->mutex.start);
	pthread_mutex_destroy(&info->mutex.print);
	pthread_mutex_destroy(&info->mutex.check_eat);
	pthread_mutex_destroy(&info->mutex.check_end);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&info->fork[i].mutex);
	free(info->fork);
}

static bool	init_info(int argc, char **argv, t_info *info)
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
	if (info->time_to_eat >= info->time_to_sleep)
	{
		if (info->num_philo % 2)
			info->time_to_think = info->time_to_eat * 2 - info->time_to_sleep;
		else
			info->time_to_think = info->time_to_eat - info->time_to_sleep;
	}
	return (true);
}

static bool	init_mutex(t_info *info)
{
	int	i;

	info->fork = (t_fork *)ft_calloc(info->num_philo, sizeof(t_fork));
	if (!info->fork)
		return (print_error(MALLOC));
	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork[i].mutex, NULL))
		{
			while (--i)
				pthread_mutex_destroy(&info->fork[i].mutex);
			free(info->fork);
			return (print_error(MUTEX));
		}
	}
	if (pthread_mutex_init(&info->mutex.start, NULL)
		|| pthread_mutex_init(&info->mutex.print, NULL)
		|| pthread_mutex_init(&info->mutex.check_eat, NULL)
		|| pthread_mutex_init(&info->mutex.check_end, NULL))
	{
		destroy_mutex(info);
		return (print_error(MUTEX));
	}
	return (true);
}

static void	init_philo(t_philo *philo, t_info *info)
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
