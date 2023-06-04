/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:46:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/04 18:11:41 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_died(t_philo *philo, int i)
{
	time_t	t;

	(void)i;
	t = ft_get_time(philo);
	pthread_mutex_lock(&philo->data->print);
	if (philo->died && !philo->data->print_die)
	{
		printf("\033[31m%ld %d died\n\033[0m", t, philo->id);
		philo->data->print_die = 1;
	}
	//pthread_mutex_unlock(&philo->data->died[i]);
	usleep(1000);
	pthread_mutex_unlock(&philo->data->print);
}

