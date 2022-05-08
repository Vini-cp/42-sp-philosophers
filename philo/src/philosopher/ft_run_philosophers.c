/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_philosophers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:25:37 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/09 00:54:26 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	ft_philosopher_sleep(t_philo *philo, long long time_to_wait)
{
	long long	beginning;

	beginning = ft_get_time_now();
	while (!(philo->has_died))
	{
		if (ft_time_diff(beginning, ft_get_time_now()) >= time_to_wait)
			break ;
		usleep(1000);
	}
}

static void	ft_philosopher_eat(t_philosopher *philosopher)
{
	t_philo	*philo;

	philo = philosopher->philo;
	pthread_mutex_lock(&(philo->forks[philosopher->left_fork_id]));
	ft_print_action(philosopher->id, E_TAKE_A_FORK, philo);
	if (philosopher->left_fork_id == philosopher->right_fork_id)
	{
		usleep(philo->time_to_die * 1000);
		pthread_mutex_unlock(&(philo->forks[philosopher->left_fork_id]));
		return ;
	}		
	pthread_mutex_lock(&(philo->forks[philosopher->right_fork_id]));
	ft_print_action(philosopher->id, E_TAKE_A_FORK, philo);
	pthread_mutex_lock(&(philosopher->last_meal_checker));
	ft_print_action(philosopher->id, E_EAT, philo);
	philosopher->last_meal_was_at = ft_get_time_now();
	pthread_mutex_unlock(&(philosopher->last_meal_checker));
	ft_philosopher_sleep(philo, philo->time_to_eat);
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
	if (philosopher->id % 2 == 0)
		usleep(1);
	while (!philo->has_died)
	{
		ft_philosopher_eat(philosopher);
		if (philo->number_of_times_each_philosopher_must_eat
			== philosopher->eat_no_times)
			break ;
		ft_print_action(philosopher->id, E_SLEEP, philo);
		ft_philosopher_sleep(philo, philo->time_to_sleep);
		ft_print_action(philosopher->id, E_THINK, philo);
	}
	pthread_mutex_lock(&(philo->finished_eating));
	philo->number_of_philosophers_who_have_eaten++;
	pthread_mutex_unlock(&(philo->finished_eating));
	return (NULL);
}
