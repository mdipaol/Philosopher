/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:46:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/21 19:34:16 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_died(t_philo *philo, int i)
{
	time_t	t;

	t = ft_get_time(philo);
	//pthread_mutex_lock(&philo->data->print);
	if (philo->data->die && !philo->data->print_die)
	{
		printf("\033[31m%ld %d died\n\033[0m", t, philo->id);
		philo->data->print_die = 1;
	}
	pthread_mutex_unlock(&philo->data->died[i]);
	usleep(1000);
	pthread_mutex_unlock(&philo->data->print);
	//ft_exit(philo->data);
}

void	ft_check_died(t_philo *philo, int i)
{
	time_t t;

	t = ft_get_time(philo);
	if (t - philo->last_meal >= philo->data->t_die)
	{
		printf("morto\n");
		pthread_mutex_lock(&philo->data->is_died);
		philo->data->die = 1;
		pthread_mutex_unlock(&philo->data->is_died);
		ft_print_died(philo, i);
	}
	else
		return ;
}
