/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:30 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/13 14:46:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}