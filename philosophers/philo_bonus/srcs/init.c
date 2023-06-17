/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:46:34 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/17 18:24:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

t_info		*init(int argc, char **argv);
void		unlink_sem(void);
static bool	init_info(int argc, char **argv, t_info *info);
static bool	init_sem(t_info *info);

t_info	*init(int argc, char **argv)
{
	t_info	*info;

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
	info->philo.id_process = (pid_t *)ft_calloc(info->num_philo, sizeof(pid_t));
	if (!info->philo.id_process)
	{
		unlink_sem();
		free(info);
		print_error(MALLOC);
		return (NULL);
	}
	return (info);
}

void	unlink_sem(void)
{
	sem_unlink("fork");
	sem_unlink("start");
	sem_unlink("print");
	sem_unlink("check_eat");
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
	info->sem.fork = sem_open("fork", O_CREAT | O_EXCL, 0644, info->num_philo);
	info->sem.start = sem_open("start", O_CREAT | O_EXCL, 0644, 0);
	info->sem.print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	info->sem.check_eat = sem_open("check_eat", O_CREAT | O_EXCL, 0644, 0);
	if (info->sem.fork == SEM_FAILED \
		|| info->sem.start == SEM_FAILED \
		|| info->sem.print == SEM_FAILED \
		|| info->sem.check_eat == SEM_FAILED)
	{
		unlink_sem();
		return (print_error(SEM));
	}
	return (true);
}
