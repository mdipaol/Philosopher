/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:30:54 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/11 15:51:40 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_print_all(t_data *data)
{

}

void	ft_create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_create(&data->thread[i], NULL, &ft_print_all, data);
	}
}

void	ft_init_all(t_data *data)
{
	data->philo = malloc (sizeof(t_philo) * data->n_philo);
	data->thread = malloc (sizeof(pthread_t) * data->n_philo);
	data->mutex = malloc (sizeof(pthread_mutex_t) * data->n_philo);
	data->forks = malloc (sizeof(int) * data->n_philo + 1);
	ft_create_thread(data);
}
