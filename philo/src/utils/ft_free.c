/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:22:42 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/05 00:48:16 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_free(t_philo *philo, t_philosopher **philosophers, int error_code)
{
	free(philo->forks);
	free(*philosophers);
	return (ft_print_error(error_code));
}
