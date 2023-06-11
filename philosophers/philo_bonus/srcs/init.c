/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:46:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/12 08:23:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

t_philo		*init(int argc, char **argv);
void		unlink_sem(void);
static bool	init_info(int argc, char **argv, t_info *info);
static bool	init_sem(t_info *info);
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
	if (init_info(argc, argv, info) == false || init_sem(info) == false)
	{
		free(info);
		return (NULL);
	}
	philo = (t_philo *)ft_calloc(info->num_philo, sizeof(t_philo));
	if (!philo)
	{
		unlink_sem();
		free(info);
		print_error(MALLOC);
		return (NULL);
	}
	init_philo(philo, info);
	return (philo);
}

void	unlink_sem(void)
{
	sem_unlink("fork");
	sem_unlink("start");
	sem_unlink("print");
	sem_unlink("check_eat");
	sem_unlink("check_end");
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

static bool	init_sem(t_info *info)
{
	unlink_sem();
	info->start = sem_open("fork", O_CREAT | O_EXCL, 0644, info->num_philo);
	info->start = sem_open("start", O_CREAT | O_EXCL, 0644, 1);
	info->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	info->check_eat = sem_open("check_eat", O_CREAT | O_EXCL, 0644, info->num_philo);
	info->check_end = sem_open("check_end", O_CREAT | O_EXCL, 0644, 1);
	if (info->fork == SEM_FAILED \
		|| info->start == SEM_FAILED \
		|| info->print == SEM_FAILED \
		|| info->check_eat == SEM_FAILED \
		|| info->check_end == SEM_FAILED)
	{
		unlink_sem();
		return (print_error(SEM));
	}
	return (true);
}

static void	init_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		philo[i].id_philo = i;
}
