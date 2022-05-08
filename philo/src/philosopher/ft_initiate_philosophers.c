/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_philosophers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:33:59 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/08 02:47:18 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static e_error	ft_create_philosophers(t_philo *philo,
										t_philosopher **philosophers)
{
	int	i;
	int	size;

	size = philo->number_of_philosophers;
	*philosophers = malloc(size * sizeof(t_philosopher));
	if (*philosophers == NULL)
		return (E_MALLOC_PHILOSOPHERS);
	i = 0;
	while (i < size)
	{
		(*philosophers)[i].id = i + 1;
		(*philosophers)[i].left_fork_id = i;
		(*philosophers)[i].right_fork_id = (i + 1) % (size);
		(*philosophers)[i].last_meal_was_at = 0;
		(*philosophers)[i].eat_no_times = 0;
		(*philosophers)[i].philo = philo;
		if (pthread_mutex_init(&((*philosophers)[i].last_meal_checker), NULL))
			return (E_INSTATIATE_MUTEX);
		i++;
	}
	return (E_SUCCESS);
}

e_error	ft_initiate_philosophers(t_philo *philo, t_philosopher **philosophers)
{
	e_error	error_no;

	error_no = ft_create_philosophers(philo, philosophers);
	if (error_no != E_SUCCESS)
	{
		if (*philosophers)
			free(*philosophers);
		return (ft_print_error(error_no));
	}
	return (E_SUCCESS);
}
