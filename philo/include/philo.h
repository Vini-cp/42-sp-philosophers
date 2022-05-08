/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:34:16 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/08 16:45:41 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_config_error
{
	E_SUCCESS,
	E_INVALID_INPUT,
	E_INVALID_NUMBER_OF_PHILOSOPHERS,
	E_INVALID_TIME_TO_DIE,
	E_INVALID_TIME_TO_EAT,
	E_INVALID_TIME_TO_SLEEP,
	E_INVALID_NUMBER_OF_TIMES_PHILOSOPHER_MUST_EAT,
	E_NOT_A_NUMBER,
	E_INSTATIATE_MUTEX,
	E_MALLOC_FORKS,
	E_MALLOC_PHILOSOPHERS,
	E_THREAD_CREATION,
	E_NBR_OF_ERRORS,
}	t_enum_error;

typedef enum e_actions
{
	E_TAKE_A_FORK,
	E_EAT,
	E_SLEEP,
	E_THINK,
	E_DIE,
	E_NBR_OF_ACTIONS,
}	t_enum_actions;

typedef struct s_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		start_time;
	int				has_died;
	int				number_of_philosophers_who_have_eaten;
	pthread_mutex_t	finished_eating;
	pthread_mutex_t	print_action;
	pthread_mutex_t	*forks;
}	t_philo;

typedef struct s_philosopher
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal_was_at;
	int				eat_no_times;
	pthread_mutex_t	last_meal_checker;
	pthread_t		thread_id;
	t_philo			*philo;
}	t_philosopher;

void			ft_exit_threads(t_philo *philo, t_philosopher **philosophers);
t_enum_error	ft_initiate_constraints(int argc, char **argv, t_philo *philo);
t_enum_error	ft_initiate_forks(t_philo *philo);
t_enum_error	ft_initiate_philosophers(t_philo *philo,
					t_philosopher **philosophers);
void			ft_philosopher_has_died(t_philosopher **philosophers);
void			*ft_run_philosophers(void *arg);
int				ft_atoi(const char *str);
int				ft_free(t_philo *philo, t_philosopher **philosophers,
					int error_code);
long long		ft_get_time_now(void);
void			ft_print_action(int philosopher_id, int action_id,
					t_philo *philo);
t_enum_error	ft_print_error(int error_code);
void			ft_print_philosophers(int size, t_philosopher *philosophers);
long long		ft_time_diff(long long before, long long after);

#endif
