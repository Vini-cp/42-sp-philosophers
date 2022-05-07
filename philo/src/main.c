/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:33:26 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/07 22:54:50 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int				i;
	t_philo			philo;
	t_philosopher	*philosophers;

	philosophers = NULL;	
	if (ft_initiate_constraints(argc, argv, &philo) != E_SUCCESS)
		return (0);
	if (ft_initiate_forks(&philo) != E_SUCCESS)
		return (0);
	if (ft_initiate_philosophers(&philo, &philosophers) != E_SUCCESS)
		return (0);
	philo.start_time = ft_get_time_now();
	i = 0;
	while (i < philo.number_of_philosophers)
	{
		philosophers[i].last_meal_was_at = philo.start_time;
		if (pthread_create(&(philosophers[i].thread_id), NULL, ft_run_philosophers, &(philosophers[i])))
			return (ft_free(&philo, &philosophers, E_THREAD_CREATION));
		i++;
	}
	ft_philosopher_has_died(&philosophers);
	ft_exit_threads(&philo, &philosophers);
	return (ft_free(&philo, &philosophers, E_SUCCESS));
}
