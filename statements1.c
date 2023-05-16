/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:46:37 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/16 11:50:41 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_died(t_philo *philo, int i)
{
	time_t	t;

	t = ft_get_time(philo);
	printf("\033[31m%ld %d died\n\033[0m", t, philo->id);
	pthread_mutex_unlock(&philo->data->died[i]);
	exit(1);
}

void	ft_check_died(t_philo *philo, int i)
{
	time_t t;

	t = ft_get_time(philo);
	if (t - philo->last_meal >= philo->data->t_die)
		ft_print_died(philo, i);
	else
		return ;
}
