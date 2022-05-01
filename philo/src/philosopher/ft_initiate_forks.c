/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:49:25 by coder             #+#    #+#             */
/*   Updated: 2022/05/01 03:33:07 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static e_error	create_forks(int size, pthread_mutex_t **forks)
{
	int	i;

	*forks = malloc(size * sizeof(pthread_mutex_t));
	if (*forks == NULL)
		return (E_MALLOC_FORKS);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&((*forks)[i]), NULL))
			return (E_INSTATIATE_MUTEX);
		i++;
	}
	return (E_SUCCESS);
}

e_error	ft_initiate_forks(t_philo *philo)
{
	e_error	error_no;

	error_no = create_forks(philo->number_of_philosophers, &philo->forks);
	if (error_no != E_SUCCESS)
	{
		if (philo->forks)
			free(philo->forks);
		return (ft_print_error(error_no));
	}
	return (E_SUCCESS);
}
