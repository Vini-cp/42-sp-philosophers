/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:21:41 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/09 01:19:11 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_exit_threads(t_philo *philo, t_philosopher **philosophers)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		pthread_join((*philosophers)[i].thread_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&(philo->finished_eating));
	pthread_mutex_destroy(&(philo->print_action));
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		pthread_mutex_destroy(&((*philosophers)[i].last_meal_checker));
		pthread_mutex_destroy(&(philo->forks[i]));
		i++;
	}
}
