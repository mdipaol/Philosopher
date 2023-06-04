/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:30:54 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/04 21:25:09 by mdi-paol         ###   ########.fr       */
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
	//int	i;
	t_philo	*philo;


	philo = (t_philo *) info;
	//i = philo->id - 1;
	if (philo->id % 2 == 0)
		usleep(5000);
	while (1)
	{
		ft_statements(philo);
		//pthread_mutex_lock(&philo->data->died[i]);
		pthread_mutex_lock(&philo->data->is_died);
		if (philo->died || philo->finish_meal)
		{
			//pthread_mutex_unlock(&philo->data->died[i]);
			pthread_mutex_unlock(&philo->data->is_died);
			break ;
		}
		pthread_mutex_unlock(&philo->data->is_died);
		//pthread_mutex_unlock(&philo->data->died[i]);
	}
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
		data->philo[i].n_t_must_eat = data->n_t_must_eat;
		data->philo[i].count_meal = 1;
		data->philo[i].data = data;
		data->philo[i].finish_meal = 0;
		data->philo[i].died = 0;
		data->philo[i].last_meal = 0;
		i++;
	}
	}

void	ft_create_all(t_data *data)
{
	int	i;

	i = 0;
	ft_init_philo(data);
	if (data->n_philo == 1)
	{
		printf("\033[32m%d %d has taken a fork\n\033[0m", data->die, 1);
		printf("\033[31m%d %d died\n\033[0m", data->t_die, 1);
		ft_exit_one_philo(data);
		return ;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->is_died, NULL);
	pthread_mutex_init(&data->last_meal, NULL);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		//pthread_mutex_init(&data->died[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_create(&data->thread[i], NULL, &ft_print_all, (void *) &data->philo[i]);
		i++;
	}
	ft_test(data);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
	ft_exit(data);
}

void	ft_init_all(t_data *data)
{
	data->philo = malloc (sizeof(t_philo) * data->n_philo);
	data->thread = malloc (sizeof(pthread_t) * data->n_philo);
	data->forks = malloc (sizeof(pthread_mutex_t) * data->n_philo);
	//data->died = malloc (sizeof(pthread_mutex_t) * data->n_philo);
	ft_create_all(data);
}
