/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:24:51 by coder             #+#    #+#             */
/*   Updated: 2022/05/07 23:53:46 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static char	*search_error(int error_code)
{
	if (error_code == E_INVALID_INPUT)
		return ("Invalid input, it should have the following arguments:\n\n"
				"- number_of_philosophers\n"
				"- time_to_die (in milliseconds)\n"
				"- time_to_eat (in milliseconds)\n"
				"- time_to_sleep (in milliseconds)\n"				
				"- (optional) number_of_times_each_philosopher_must_eat\n");
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
	else if (error_code == E_NOT_A_NUMBER)
		return ("Wrong input, only number are accepted!");
	else if (error_code == E_INSTATIATE_MUTEX)
		return ("Mutex error.");
	else if (error_code == E_MALLOC_FORKS)
		return ("Error allocation memory for forks.");
	else if (error_code == E_MALLOC_PHILOSOPHERS)
		return ("Error allocation memory for philosophers.");
	else
		return ("No message error with this code.");
}

e_error	ft_print_error(int error_code)
{
	if (error_code == E_SUCCESS)
		return (E_SUCCESS);
	printf("%s\n", search_error(error_code));
	return (error_code);
}
