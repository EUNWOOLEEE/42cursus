/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:30:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 18:25:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

bool	all_free(t_philo **philo, t_info **info)
{
	int	error;
	int	i;
	
	error = (*info)->error;
	i = 0;
	while (i < (*info)->num_philo)
	{
		pthread_mutex_destroy(&(*info)->fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&(*info)->print);
	free((*info)->fork);
	free(*info);
	free(*philo);
	*info = 0;
	*philo = 0;
	return (error);
}