/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:06:36 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/16 11:55:35 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_philo *philo)
{
	time_t	t;

	t = ft_get_time(philo);
	printf("\033[35m%ld %d is thinking\n\033[0m", t, philo->id);
}

void	ft_sleeping(t_philo *philo)
{
	time_t	t;

	t = ft_get_time(philo);
	usleep(philo->t_sleep * 1000);
	printf("\033[34m%ld %d is sleeping\n\033[0m", t, philo->id);
	ft_thinking(philo);
}

void	ft_eating(t_philo *philo, int i)
{
	time_t	t;

	t = ft_get_time(philo);
	if (philo->id % philo->data->n_philo != 0)
	{
		philo->last_meal = ft_get_time(philo);
		printf("\033[33m%ld %d is eating\n\033[0m", t, philo->id);
		usleep(philo->data->t_eat * 1000);
		pthread_mutex_unlock(&philo->data->forks[i]);
		//printf("\033[31mphil n %d leave l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		pthread_mutex_unlock(&philo->data->forks[i + 1 % philo->data->n_philo]);
		//printf("\033[31mphil n %d leave r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1 % philo->data->n_philo]);
	}
	else
	{
		philo->last_meal = ft_get_time(philo);
		printf("\033[33m%ld %d is eating\n\033[0m", t, philo->id);
		usleep(philo->data->t_eat * 1000);
		//printf("\033[31mphil n %d leave l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		pthread_mutex_unlock(&philo->data->forks[0]);
		//printf("\033[31mphil n %d leave r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1 % philo->data->n_philo]);
		pthread_mutex_unlock(&philo->data->forks[i]);
	}
	ft_sleeping(philo);
}

void	ft_forks(t_philo *philo)
{
	int	i;
	time_t	t;

	i = philo->id - 1;
	t = ft_get_time(philo);
	if (philo->id % philo->data->n_philo != 0)
	{
		pthread_mutex_lock(&philo->data->forks[i]);
		//printf("\033[32mphil n %d taken l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		pthread_mutex_lock(&philo->data->forks[i + 1 % philo->data->n_philo]);
		//printf("\033[32mphil n %d taken r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1% philo->data->n_philo]);
		printf("\033[32m%ld %d has taken a fork\n\033[0m", t, philo->id);
		ft_eating(philo, i);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[0]);
		//printf("\033[32mphil n %d taken r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1% philo->data->n_philo]);
		pthread_mutex_lock(&philo->data->forks[i]);
		//printf("\033[32mphil n %d taken l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		printf("\033[32m%ld %d has taken a fork\n\033[0m", t, philo->id);
		ft_eating(philo, i);
	}
}

void	ft_statements(t_philo *philo)
{
	ft_forks(philo);
}
