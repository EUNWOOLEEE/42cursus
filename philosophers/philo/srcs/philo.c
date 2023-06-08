/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:13:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 08:45:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

//스레드가 각자 모니터링

// void asd()
// {
// 	system("leaks philo");
// }

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

// 5 800 200 200 (계속) o
// 5 410 200 200 (죽음) o
// 200 410 200 200 x
// 200 800 200 200 x
// 199 610 200 200 x
// 시간이 0일 때 o
// 1명일 때