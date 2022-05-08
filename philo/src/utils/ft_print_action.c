/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:01:02 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/08 16:45:10 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_print_action(int philosopher_id, int action_id, t_philo *philo)
{
	long long	time;
	char		*action[E_NBR_OF_ACTIONS];

	action[E_TAKE_A_FORK] = "has taken a fork\n";
	action[E_EAT] = "is eating\n";
	action[E_SLEEP] = "is sleeping\n";
	action[E_THINK] = "is thinking\n";
	action[E_DIE] = "died\n";
	time = ft_time_diff(philo->start_time, ft_get_time_now());
	pthread_mutex_lock(&(philo->print_action));
	if (!philo->has_died)
		printf("%.4lld philo_%d %s", time, philosopher_id, action[action_id]);
	pthread_mutex_unlock(&(philo->print_action));
}
