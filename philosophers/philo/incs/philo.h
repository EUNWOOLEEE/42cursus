/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:47:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/30 19:30:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_philo
{
	pthread_t	number;
	int			state;
}	t_philo;

typedef struct s_info
{
	int		num_philo;
	size_t	time_die;
	size_t	time_eat;
	size_t	time_sleep;
	int		num_eat;
	t_philo	*philos;
}	t_info;

t_info *init(int argc, char **argv);
size_t	ft_atos(char *str);

#endif