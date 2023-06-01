/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:30:06 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/01 06:33:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void all_free(t_philo **philo, t_info **info)
{
	free((*info)->fork);
	free((*info)->fork_mutex);
	free(*info);
	free(*philo);
	*info = 0;
	*philo = 0;
}