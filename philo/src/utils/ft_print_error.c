/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:24:51 by coder             #+#    #+#             */
/*   Updated: 2022/04/25 01:39:20 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static char	*search_error(int error_code)
{
	if (error_code == E_INVALID_INPUT)
		return ("Invalid input, \
			it should have the following arguments: number_of_philosophers \
			time_to_die time_to_eat time_to_sleep \
			[number_of_times_each_philosopher_must_eat].");
	else if (error_code == E_INVALID_NUMBER_OF_PHILOSOPHERS)
		return ("Number of philosophers must be positive.");
	else if (error_code == E_INVALID_TIME_TO_DIE)
		return ("Time to die must be positive.");
	else if (error_code == E_INVALID_TIME_TO_EAT)
		return ("Time to eat must be positive.");
	else if (error_code == E_INVALID_TIME_TO_SLEEP)
		return ("Time to sleep must be positive.");
	else if (error_code == E_INVALID_NUMBER_OF_TIMES_PHILOSOPHER_MUST_EAT)
		return ("Number of times each philosopher eat must be positive.");
	else if (error_code == E_INSTATIATE_MUTEX)
		return ("Mutex error.");
	else
		return ("No message error with this code.");
}

int	ft_print_error(int error_code)
{
	printf("%s\n", search_error(error_code));
	return (error_code);
}
