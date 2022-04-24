/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:34:16 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/24 23:13:27 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef enum e_config_error
{
	E_SUCCESS,
	E_INVALID_INPUT,
	E_INVALID_NUMBER_OF_PHILOSOPHERS,
	E_INVALID_TIME_TO_DIE,
	E_INVALID_TIME_TO_EAT,
	E_INVALID_TIME_TO_SLEEP,
	E_INVALID_NUMBER_OF_TIMES_PHILOSOPHER_MUST_EAT,
	E_INSTATIATE_MUTEX,
	E_NBR_OF_ERRORS,
}	t_error;

typedef struct s_erro_rdesc {
	int		code;
	char	*message;
}	t_error_desc;

typedef struct s_philosopher
{
	int			id;
	int			left_fork_id;
	int			right_fork_id;
	int			time_since_last_meal;
	pthread_t	thread_id;
}	t_philosopher;

typedef struct s_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}	t_philo;

int			ft_initiate_constraints(int argc, char **argv, t_philo *philo);
int			ft_initiate_philosophers(t_philo *philo);
int			ft_atoi(const char *str);
void		ft_free(t_philo *philo);
long long	ft_get_time_now(void);
int			ft_print_error(int error_code);

#endif
