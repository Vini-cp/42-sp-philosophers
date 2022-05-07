/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_constraints.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:11:53 by coder             #+#    #+#             */
/*   Updated: 2022/05/07 23:55:34 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static e_error	ft_check_chars(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i <= argc)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (E_NOT_A_NUMBER);
			j++;
		}
		i++;
	}
	return (E_SUCCESS);
}

static e_error	ft_check_input(t_philo *philo, int argc)
{
	philo->forks = NULL;
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
	else if (argc == 5)
		philo->number_of_times_each_philosopher_must_eat = -1;
	return (E_SUCCESS);
}

e_error	ft_initiate_constraints(int argc, char **argv, t_philo *philo)
{
	int	error_no;
	
	error_no = ft_check_chars(argc, argv);
	if (error_no != E_SUCCESS)
		return (ft_print_error(error_no));
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->has_died = 0;
	philo->number_of_philosophers_who_have_eaten = 0;
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	error_no = ft_check_input(philo, argc);
	if (error_no != E_SUCCESS)
		return (ft_print_error(error_no));
	return (E_SUCCESS);
}
