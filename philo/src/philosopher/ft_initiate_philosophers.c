/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_philosophers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:49:25 by coder             #+#    #+#             */
/*   Updated: 2022/04/25 01:38:38 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	create_forks(t_philo *philo)
{
	int	i;

	philo->forks = malloc(
			philo->number_of_philosophers * sizeof(pthread_mutex_t));
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (pthread_mutex_init(&(philo->forks[i]), NULL))
			return (E_INSTATIATE_MUTEX);
		i++;
	}
	return (E_SUCCESS);
}

static void	create_philosophers(t_philo *philo)
{
	int	i;

	philo->philosophers = malloc(
			philo->number_of_philosophers * sizeof(t_philosopher));
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		(philo->philosophers[i]).id = i + 1;
		(philo->philosophers[i]).left_fork_id = i;
		(philo->philosophers[i]).right_fork_id = i
			% (philo->number_of_philosophers) + 1;
		(philo->philosophers[i]).time_since_last_meal = 0;
		i++;
	}	
}

int	ft_initiate_philosophers(t_philo *philo)
{
	int	error_no;

	error_no = create_forks(philo);
	if (error_no != E_SUCCESS)
	{
		ft_free(philo);
		return (ft_print_error(error_no));
	}
	create_philosophers(philo);
	return (E_SUCCESS);
}
