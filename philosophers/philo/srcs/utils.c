/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:27:39 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/11 16:21:15 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

ULL		ft_atoull(char *str);
void	*ft_calloc(size_t count, size_t size);
t_bool	get_cur_time(ULL *time);
t_bool	print_time(t_philo *philo, t_info *info, char *state);

ULL	ft_atoull(char *str)
{
	ULL	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	memset(tmp, 0, size * count);
	return (tmp);
}

t_bool	get_cur_time(ULL *time)
{
	struct timeval *tv;

	tv = NULL;
	if	(gettimeofday(tv, NULL) == -1)
		return (FALSE);
	*time = (ULL)tv->tv_usec;
	return (TRUE);
}

t_bool	print_time(t_philo *philo, t_info *info, char *state)
{
	ULL	cur_time;

	if (get_cur_time(&cur_time) == FALSE)
	 	return (FALSE);
	if (pthread_mutex_lock(&info->print))
		return (FALSE);
	printf("%lld %d %s\n", cur_time, philo->id + 1, state);
	if (pthread_mutex_unlock(&info->print))
		return (FALSE);
	return (TRUE);
}