/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_constraints.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:11:53 by coder             #+#    #+#             */
/*   Updated: 2022/04/24 23:04:10 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	check_input(t_philo *philo, int argc)
{
	if (philo->number_of_philosophers <= 0)
		return (E_INVALID_NUMBER_OF_PHILOSOPHERS);
	else if (philo->time_to_die <= 0)
		return (E_INVALID_TIME_TO_DIE);
	else if (philo->time_to_eat <= 0)
		return (E_INVALID_TIME_TO_EAT);
	else if (philo->time_to_sleep <= 0)
		return (E_INVALID_TIME_TO_SLEEP);
	if (argc == 6 && philo->number_of_times_each_philosopher_must_eat <= 0)
		return (E_INVALID_NUMBER_OF_TIMES_PHILOSOPHER_MUST_EAT);
	else
		philo->number_of_times_each_philosopher_must_eat = -1;
	return (E_SUCCESS);
}

int	ft_initiate_constraints(int argc, char **argv, t_philo *philo)
{
	int	error_no;

	if (argc < 5 || argc > 6)
		return (ft_print_error(E_INVALID_INPUT));
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	error_no = check_input(philo, argc);
	if (error_no != E_SUCCESS)
		return (ft_print_error(error_no));
	return (E_SUCCESS);
}
