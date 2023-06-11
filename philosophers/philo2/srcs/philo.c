/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/11 19:16:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// void asd()
// {
// 	system("leaks philo");
// }

//philo - 원본
//philo2 - init 정리하는중

int	main(int argc, char **argv)
{
	t_philo	*philo;

	// atexit(asd);
	
	if (argc != 5 && argc != 6)
		return (print_error(USAGE));
	philo = init(argc, argv);
	if (!philo)
		return (1);
	start(philo, philo->info);
	return (all_free(&philo, &philo->info));
}
