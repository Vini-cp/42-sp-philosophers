/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:01:02 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/05 00:44:17 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_print_action(int action_id, int philosopher_id)
{
	printf("%lld %d ", ft_get_time_now(), philosopher_id);
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
