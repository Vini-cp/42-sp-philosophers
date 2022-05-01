/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:33:26 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/01 18:13:34 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_philosopher	*philosophers;

	philosophers = NULL;
	if (ft_initiate_constraints(argc, argv, &philo) != E_SUCCESS)
		return (0);
	if (ft_initiate_forks(&philo) != E_SUCCESS)
		return (0);
	if (ft_initiate_philosophers(&philo, &philosophers) != E_SUCCESS)
		return (0);
	// ft_print_philosophers(philo.number_of_philosophers, philosophers);
	ft_run_philosophers(philosophers);
	free(philo.forks);
	free(philosophers);
	return (0);
}
