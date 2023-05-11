/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:04:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/11 16:19:36 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_philo			*init(int argc, char **argv);
static t_bool	init_info(t_info *info, int argc, char **argv);
static t_bool	init_mutex(t_info *info);
static t_bool	init_philos(t_philo **philo, t_info *info);

t_philo	*init(int argc, char **argv)
{
	t_info	info;
	t_philo *philo;

	if (init_info(&info, argc, argv) == FALSE
		|| init_philos(&philo, &info) == FALSE)
		return (0);
	return (philo);
}

static t_bool	init_info(t_info *info, int argc, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->num_philo = (int)ft_atoull(argv[1]);
	info->time_die = ft_atoull(argv[2]);
	info->time_eat = ft_atoull(argv[3]);
	info->time_sleep = ft_atoull(argv[4]);
	if (get_cur_time(&info->time_start) == FALSE)
		return (FALSE);
	if (argc == 6)
		info->num_eat = (int)ft_atoull(argv[5]);
	info->forks = (pthread_mutex_t *)ft_calloc(info->num_philo, sizeof(pthread_mutex_t));
	if (!info->forks)
		return (FALSE);
	if (init_mutex(info) == FALSE)
	{
		free(info->forks);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	init_mutex(t_info *info)
{
	int	idx;

	if (pthread_mutex_init(&(*info).print, NULL) == -1)
		return (FALSE);
	idx = 0;
	while (idx < (*info).num_philo)
	{
		if (pthread_mutex_init(&(*info).forks[idx], NULL) == -1)
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

static t_bool	init_philos(t_philo **philo, t_info *info)
{
	int	idx;

	*philo = (t_philo *)ft_calloc(info->num_philo, sizeof(t_philo));
	if (*philo)
		return (FALSE);
	idx = 0;
	while (idx < info->num_philo)
	{
		(*philo[idx]).info = info;
		(*philo[idx]).id = idx;
		(*philo[idx]).left = idx;
		(*philo[idx]).right = (idx + 1) % info->num_philo;
		idx++;
	}
	return (TRUE);
}