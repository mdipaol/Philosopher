/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:06:36 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/11 22:41:21 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eating(t_data *data)
{
	printf("phil n")
}

void	ft_forks(t_data *data)
{
	pthread_mutex_lock(&data->forks[data->philo->id % 2 != 0]);
	printf("phil n %d, taken a fork\n", data->philo[0].id);
	usleep(1000000);
	ft_eating(data);
	pthread_mutex_unlock(&data->forks[data->philo->id % 2 != 0]);
}

void	ft_statements(t_data *data)
{
	ft_forks(data);
}
