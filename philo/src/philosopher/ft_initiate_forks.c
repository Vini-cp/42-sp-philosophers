/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:49:25 by coder             #+#    #+#             */
/*   Updated: 2022/05/08 02:58:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static t_enum_error	ft_create_forks(int size, t_philo *philo)
{
	int	i;

	philo->forks = malloc(size * sizeof(pthread_mutex_t));
	if (philo->forks == NULL)
		return (E_MALLOC_FORKS);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&(philo->forks[i]), NULL))
			return (E_INSTATIATE_MUTEX);
		i++;
	}
	return (E_SUCCESS);
}

static t_enum_error	ft_create_eat_checker(t_philo *philo)
{
	if (pthread_mutex_init(&(philo->finished_eating), NULL))
		return (E_INSTATIATE_MUTEX);
	return (E_SUCCESS);
}

t_enum_error	ft_initiate_forks(t_philo *philo)
{
	t_enum_error	error_no;

	error_no = ft_create_forks(philo->number_of_philosophers, philo);
	error_no = ft_create_eat_checker(philo);
	if (error_no != E_SUCCESS)
	{
		if (philo->forks)
			free(philo->forks);
		return (ft_print_error(error_no));
	}
	return (E_SUCCESS);
}
