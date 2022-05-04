/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:21:41 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/05 01:23:49 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_exit_threads(t_philosopher *philosophers)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = philosophers->philo;
	pthread_mutex_destroy(&(philo->finished_eating));
	while (i < philo->number_of_philosophers)
	{
		pthread_join(philosophers[i].thread_id, NULL);
		pthread_mutex_destroy(&(philosophers[i].last_meal_checker));
		pthread_mutex_destroy(&(philo->forks[i]));
		i++;
	}
}
