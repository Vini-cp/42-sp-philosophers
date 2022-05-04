/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philosophers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:22:35 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/05 01:02:39 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	ft_print_constraints(t_philo *philo)
{
	printf("=============================================================\n");
	printf("NO_PHILO: %d\n", philo->number_of_philosophers);
	printf("TIME DIE: %d\n", philo->time_to_die);
	printf("TIME EAT: %d\n", philo->time_to_eat);
	printf("TIME SLP: %d\n", philo->time_to_sleep);
	printf("EAT NO T: %d\n", philo->number_of_times_each_philosopher_must_eat);
	printf("=============================================================\n");
}

void	ft_print_philosophers(int size, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			ft_print_constraints(philosophers->philo);
		else
			printf("-------------------------------------------------------------\n");
		printf("ID      : %d\n", philosophers[i].id);
		printf("LF ID   : %d\n", philosophers[i].left_fork_id);
		printf("RF ID   : %d\n", philosophers[i].right_fork_id);
		printf("TIME LM : %lld\n", philosophers[i].last_meal_was_at);
		printf("EAT NO  : %d\n", philosophers[i].eat_no_times);
		i++;
	}
	printf("-------------------------------------------------------------\n");
}
