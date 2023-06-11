/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:46:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/11 18:44:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_philo		*init(int argc, char **argv);
static bool	init_info(int argc, char **argv, t_info *info);
static bool	init_sem(t_info *info);
static bool	init_fork(t_info *info);
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
	if (init_info(argc, argv, info) == false \
		|| init_sem(info) == false || init_fork(info) == false) // sem unlink 수정하기
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
	info->end = false;
	info->error = false;
	if (info->time_to_eat >= info->time_to_sleep)
	{
		if (info->num_philo % 2)
			info->time_to_think = info->time_to_eat * 2 - info->time_to_sleep;
		else
			info->time_to_think = info->time_to_eat - info->time_to_sleep;
	}
	return (true);
}

static bool	init_sem(t_info *info)
{
	info->start = sem_open("start", O_CREAT | O_EXCL, 0644, 1);
	if (info->start == SEM_FAILED)
		return (print_error(SEM));
	info->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (info->print == SEM_FAILED)
	{
		sem_unlink("start");
		return (print_error(SEM));
	}
	info->check_eat = sem_open("check_eat", O_CREAT | O_EXCL, 0644, 1);
	if (info->check_eat == SEM_FAILED)
	{
		sem_unlink("start");
		sem_unlink("print");
		return (print_error(SEM));
	}
	info->check_end = sem_open("check_end", O_CREAT | O_EXCL, 0644, 1);
	if (info->check_end == SEM_FAILED)
	{
		sem_unlink("start");
		sem_unlink("print");
		sem_unlink("check_end");
		return (print_error(SEM));
	}
	return (true);
}

static bool	init_fork(t_info *info)
{
	int		i;
	char	num[2];

	info->fork = (t_fork *)ft_calloc(info->num_philo, sizeof(t_fork));
	if (!info->fork)
		return (print_error(MALLOC));
	i = -1;
	while (++i < info->num_philo)
	{
		num[0] = i + '0';
		num[1] = '\0';
		info->fork[i].name = ft_strjoin("fork", num);
		info->fork[i].sem = sem_open(info->fork[i].name, O_CREAT | O_EXCL, 0644, 1);
		if (info->fork[i].sem == SEM_FAILED)
		{
			sem_unlink(info->fork[i].name);
			info->fork[i].sem = sem_open(info->fork[i].name, O_CREAT | O_EXCL, 0644, 1);
			if (info->fork[i].sem == SEM_FAILED)
			{
				free(info->fork);
				return (print_error(SEM));
			}
		}
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
