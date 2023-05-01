/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:39:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/30 19:19:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// ./philo [number_of_philosophers] [time_to_die] [time_to_eat]
//  [time_to_sleep] [number_of_times_each_philosopher_must_eat]

int main(int argc, char **argv)
{
	t_info	*info;
	
	if (argc != 5 || argc != 6)
		return (0); //usage
	info = init(argc, argv);
}