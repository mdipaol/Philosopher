/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:06:36 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/04 21:21:47 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_philo *philo)
{
	time_t	t;

	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->is_died);
	if ((!philo->data->die && !philo->finish_meal) || (!philo->data->die && philo->finish_meal))
	{
		t = ft_get_time(philo);
		printf("\033[35m%ld %d is thinking\n\033[0m", t, philo->id);
	}
	pthread_mutex_unlock(&philo->data->is_died);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_sleeping(t_philo *philo)
{
	time_t	t;

	usleep(philo->t_sleep * 1000);
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->is_died);
	if ((!philo->data->die && !philo->finish_meal) || (!philo->data->die && philo->finish_meal))
	{
		t = ft_get_time(philo);
		printf("\033[34m%ld %d is sleeping\n\033[0m", t, philo->id);
	}
	pthread_mutex_unlock(&philo->data->is_died);
	pthread_mutex_unlock(&philo->data->print);
	ft_thinking(philo);
}

void	ft_eating(t_philo *philo, int i)
{
	time_t	t;

	if (philo->id % philo->data->n_philo != 0)
	{
		pthread_mutex_lock(&philo->data->is_died);
		if (!philo->died)
		{
			pthread_mutex_unlock(&philo->data->is_died);
			pthread_mutex_lock(&philo->data->last_meal);
			philo->last_meal = ft_get_time(philo);
			pthread_mutex_unlock(&philo->data->last_meal);
		}
		else
			pthread_mutex_unlock(&philo->data->is_died);
		pthread_mutex_lock(&philo->data->print);
		usleep(1000);
		if (philo->count_meal == philo->n_t_must_eat && philo->data->n_t_must_eat_exists && !philo->finish_meal)
		{
			pthread_mutex_lock(&philo->data->last_meal);
			philo->finish_meal = 1;
			pthread_mutex_unlock(&philo->data->last_meal);
		}
		pthread_mutex_lock(&philo->data->is_died);
		if ((!philo->data->die && !philo->finish_meal) || (!philo->data->die && philo->finish_meal))
		{
			t = ft_get_time(philo);
			printf("\033[33m%ld %d is eating\n\033[0m", t, philo->id);
		}
		pthread_mutex_unlock(&philo->data->is_died);
		philo->count_meal++;
		pthread_mutex_unlock(&philo->data->print);
		usleep(philo->data->t_eat * 1000);
		pthread_mutex_unlock(&philo->data->forks[i]);
		pthread_mutex_unlock(&philo->data->forks[i + 1 % philo->data->n_philo]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->is_died);
		if (!philo->died)
		{
			pthread_mutex_unlock(&philo->data->is_died);
			pthread_mutex_lock(&philo->data->last_meal);
			philo->last_meal = ft_get_time(philo);
			pthread_mutex_unlock(&philo->data->last_meal);
		}
		else
			pthread_mutex_unlock(&philo->data->is_died);
		pthread_mutex_lock(&philo->data->print);
		if (philo->count_meal == philo->n_t_must_eat && philo->data->n_t_must_eat_exists && !philo->finish_meal)
		{
			pthread_mutex_lock(&philo->data->last_meal);
			philo->finish_meal = 1;
			pthread_mutex_unlock(&philo->data->last_meal);
		}
		pthread_mutex_lock(&philo->data->is_died);
		if ((!philo->data->die && !philo->finish_meal) || (!philo->data->die && philo->finish_meal))
		{
			t = ft_get_time(philo);
			printf("\033[33m%ld %d is eating\n\033[0m", t, philo->id);
		}
		pthread_mutex_unlock(&philo->data->is_died);
		philo->count_meal++;
		pthread_mutex_unlock(&philo->data->print);
		usleep(philo->data->t_eat * 1000);
		pthread_mutex_unlock(&philo->data->forks[0]);
		pthread_mutex_unlock(&philo->data->forks[i]);
	}
	ft_sleeping(philo);
}

void	ft_forks(t_philo *philo)
{
	int	i;
	time_t	t;

	i = philo->id - 1;
	if (philo->id % philo->data->n_philo != 0)
	{
		pthread_mutex_lock(&philo->data->forks[i]);
		pthread_mutex_lock(&philo->data->forks[i + 1 % philo->data->n_philo]);
		pthread_mutex_lock(&philo->data->print);
		pthread_mutex_lock(&philo->data->is_died);
		if ((!philo->data->die && !philo->finish_meal) || (!philo->data->die && philo->finish_meal))
		{
			pthread_mutex_unlock(&philo->data->is_died);
			t = ft_get_time(philo);
			printf("\033[32m%ld %d has taken a fork\n\033[0m", t, philo->id);
		}
		else
			pthread_mutex_unlock(&philo->data->is_died);
		pthread_mutex_unlock(&philo->data->print);
		ft_eating(philo, i);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[0]);
		pthread_mutex_lock(&philo->data->forks[i]);
		pthread_mutex_lock(&philo->data->print);
		pthread_mutex_lock(&philo->data->is_died);
		if ((!philo->data->die && !philo->finish_meal) || (!philo->data->die && philo->finish_meal))
		{
			pthread_mutex_unlock(&philo->data->is_died);
			t = ft_get_time(philo);
			printf("\033[32m%ld %d has taken a fork\n\033[0m", t, philo->id);
		}
		else
			pthread_mutex_unlock(&philo->data->is_died);
		pthread_mutex_unlock(&philo->data->print);
		ft_eating(philo, i);
	}

}

void	ft_statements(t_philo *philo)
{
	ft_forks(philo);
}
