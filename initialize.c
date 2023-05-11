/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:30:54 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/11 22:07:45 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	struct timeval time;
	time_t tempo;

	gettimeofday(&time, NULL);

	tempo = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	printf("%ld", tempo); */

#include "philosophers.h"

void	*ft_print_all(void *info)
{
	t_data	*data;

	data = (t_data *) info;
	if (data->philo->id % 2 == 0)
		usleep(30);
	ft_statements(data);
	return (NULL);
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].t_eat = data->t_eat;
		data->philo[i].t_sleep = data->t_sleep;
		i++;
	}
}

void	ft_create_all(t_data *data)
{
	int	i;

	i = 0;
	ft_init_philo(data);
	while (i < data->n_philo)
	{
		pthread_create(&data->thread[i], NULL, &ft_print_all, (void *) data);
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
}

void	ft_init_all(t_data *data)
{
	data->philo = malloc (sizeof(t_philo) * data->n_philo);
	data->thread = malloc (sizeof(pthread_t) * data->n_philo);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->n_philo);
	ft_create_all(data);
}
