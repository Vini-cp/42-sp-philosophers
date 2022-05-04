/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:25:37 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/05 01:22:44 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	ft_philosopher_eat(t_philosopher *philosopher)
{
	t_philo	*philo;

	philo = philosopher->philo;
	pthread_mutex_lock(&(philo->forks[philosopher->left_fork_id]));
	ft_print_action(philosopher->id, E_TAKE_A_FORK);
	pthread_mutex_lock(&(philo->forks[philosopher->right_fork_id]));
	ft_print_action(philosopher->id, E_TAKE_A_FORK);
	pthread_mutex_lock(&(philosopher->last_meal_checker));
	ft_print_action(philosopher->id, E_EAT);
	philosopher->last_meal_was_at = ft_get_time_now();
	pthread_mutex_unlock(&(philosopher->last_meal_checker));
	philosopher->eat_no_times++;
	pthread_mutex_unlock(&(philo->forks[philosopher->left_fork_id]));
	pthread_mutex_unlock(&(philo->forks[philosopher->right_fork_id]));
}

void	*ft_run_philosophers(void *arg)
{
	t_philosopher	*philosopher;
	t_philo			*philo;

	philosopher = (t_philosopher *)arg;
	philo = philosopher->philo;
	while (!philo->has_died)
	{
		ft_philosopher_eat(philosopher);
		if (philo->number_of_times_each_philosopher_must_eat
			== philosopher->eat_no_times)
			break ;
		ft_print_action(philosopher->id, E_SLEEP);
		usleep(philo->time_to_sleep);
		ft_print_action(philosopher->id, E_THINK);
	}
	pthread_mutex_lock(&(philo->finished_eating));
	philo->number_of_philosophers_who_have_eaten++;
	pthread_mutex_unlock(&(philo->finished_eating));
	return (NULL);
}
