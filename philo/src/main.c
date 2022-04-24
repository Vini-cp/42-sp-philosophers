/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:33:26 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/24 23:06:26 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (ft_initiate_constraints(argc, argv, &philo) != E_SUCCESS)
		return (0);
	if (ft_initiate_philosophers(&philo) != E_SUCCESS)
		return (0);
	ft_free(&philo);
	return (0);
}
