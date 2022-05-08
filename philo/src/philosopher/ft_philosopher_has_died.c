/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher_has_died.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:26:03 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/08 23:34:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_philosopher_has_died(t_philosopher **philosophers)
{
	int		i;
	t_philo	*philo;

	philo = (*philosophers)->philo;
	while (1)
	{
		i = 0;
		while (!philo->has_died && i < philo->number_of_philosophers)
		{
			pthread_mutex_lock(&((*philosophers)[i].last_meal_checker));
			if (ft_time_diff((*philosophers)[i].last_meal_was_at,
				ft_get_time_now()) > philo->time_to_die)
			{
				ft_print_action((*philosophers)[i].id, E_DIE, philo);
				philo->has_died = 1;
			}
			pthread_mutex_unlock(&((*philosophers)[i].last_meal_checker));
			usleep(1);
			i++;
		}
		if (philo->has_died || philo->number_of_philosophers_who_have_eaten
			== philo->number_of_philosophers)
			break ;
	}
}
