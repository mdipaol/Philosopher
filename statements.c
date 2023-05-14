/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:06:36 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/14 19:32:50 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleeping()

void	ft_eating(t_philo *philo, int i)
{
	if (philo->id % philo->data->n_philo != 0)
	{
		printf("\033[33mphil n %d is eating\n\033[0m", philo->id);
		usleep(philo->data->t_eat * 1000);
		pthread_mutex_unlock(&philo->data->forks[i]);
		printf("\033[31mphil n %d leave l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		pthread_mutex_unlock(&philo->data->forks[i + 1 % philo->data->n_philo]);
		printf("\033[31mphil n %d leave r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1 % philo->data->n_philo]);
	}
	else
	{
		printf("\033[33mphil n %d is eating\n\033[0m", philo->id);
		usleep(philo->data->t_eat * 1000);
		printf("\033[31mphil n %d leave l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		pthread_mutex_unlock(&philo->data->forks[0]);
		printf("\033[31mphil n %d leave r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1 % philo->data->n_philo]);
		pthread_mutex_unlock(&philo->data->forks[i]);
	}
	ft_sleeping(philo);
}

void	ft_forks(t_philo *philo)
{
	int	i;

	i = philo->id - 1;
	if (philo->id % philo->data->n_philo != 0)
	{
		pthread_mutex_lock(&philo->data->forks[i]);
		printf("\033[32mphil n %d taken l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		pthread_mutex_lock(&philo->data->forks[i + 1 % philo->data->n_philo]);
		printf("\033[32mphil n %d taken r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1% philo->data->n_philo]);
		ft_eating(philo, i);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[0]);
		printf("\033[32mphil n %d taken r-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i + 1% philo->data->n_philo]);
		pthread_mutex_lock(&philo->data->forks[i]);
		printf("\033[32mphil n %d taken l-fork ||| %p\n\033[0m", philo->id, &philo->data->forks[i % philo->data->n_philo]);
		ft_eating(philo, i);
	}
}

void	ft_statements(t_philo *philo)
{
	ft_forks(philo);
}
