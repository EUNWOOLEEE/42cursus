/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:04:38 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/30 19:36:29 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static void		get_info(t_info *info, int argc, char **argv);
static t_bool	get_philos(t_info *info);

t_info	*init(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info) * 1);
	if (!info)
		return (0); //error
	memset(info, 0, sizeof(t_info *));
	get_info(info, argc, argv);
	if (get_philos == FALSE)
		return (0); //error
	return (info);
}

static void	get_info(t_info *info, int argc, char **argv)
{
	info->num_philo = (int)ft_atos(argv[1]);
	info->time_die = ft_atos(argv[2]);
	info->time_eat = ft_atos(argv[3]);
	info->time_sleep = ft_atos(argv[4]);
	if (argc == 6)
		info->num_eat = (int)ft_atos(argv[5]);
	else
		info->num_eat = 0;
}

static t_bool	get_philos(t_info *info)
{
	info->philos = (t_philo *)malloc(sizeof (t_philo) * info->num_philo);
	if (!info->philos)
		return (FALSE);
	memset(info->philos, 0, sizeof(t_philo) * info->num_philo);
	return (TRUE);
}