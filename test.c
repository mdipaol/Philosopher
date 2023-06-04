/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:00:12 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/04 20:59:22 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_check_is_died(void	*info)
{
	t_philo	*philo;
	time_t t;
	int	i;

	i = 0;
	philo = (t_philo *) info;
	while (1)
	{
		pthread_mutex_lock(&philo->data->last_meal);
		t = ft_get_time(philo);
		if (t - philo->last_meal >= philo->data->t_die && !philo->finish_meal)
		{
			pthread_mutex_lock(&philo->data->is_died);
			philo->died = 1;
			pthread_mutex_unlock(&philo->data->is_died);
			pthread_mutex_lock(&philo->data->is_died);
			philo->data->die = 1;
			pthread_mutex_unlock(&philo->data->is_died);
			ft_print_died(philo, i);
			pthread_mutex_unlock(&philo->data->last_meal);
			break;
		}
		else if (philo->finish_meal)
		{
			pthread_mutex_unlock(&philo->data->last_meal);
			break;
		}
		pthread_mutex_unlock(&philo->data->last_meal);
	}
	return (NULL);
}


void	ft_test(t_data *data)
{
	int	i;

	i = 0;
	data->is_died_true = malloc (sizeof(pthread_t) * data->n_philo);
	while (i < data->n_philo)
	{
		pthread_create(&data->is_died_true[i], NULL, &ft_check_is_died, (void *) &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->is_died_true[i], NULL);
		i++;
	}
}
