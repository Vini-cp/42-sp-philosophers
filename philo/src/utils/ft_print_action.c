/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:01:02 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/05 02:10:41 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_print_action(int action_id, int philosopher_id, long long start_time)
{
	long long	time_to_print;

	time_to_print = ft_time_diff(start_time, ft_get_time_now());
	printf("%lld %d ", time_to_print, philosopher_id);
	if (action_id == E_TAKE_A_FORK)
		printf("has taken a fork\n");
	else if (action_id == E_EAT)
		printf("is eating\n");
	else if (action_id == E_SLEEP)
		printf("is sleeping\n");
	else if (action_id == E_THINK)
		printf("is thinking\n");
	else if (action_id == E_DIE)
		printf("died\n");
}
