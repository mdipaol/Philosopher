/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:17:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/21 18:39:57 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	j;
	long int	r;

	i = 0;
	j = 1;
	r = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = (r * 10) + (nptr[i] - '0');
		i++;
	}
	return (r * j);
}

time_t	ft_get_time(t_philo *philo)
{
	struct timeval time;
	time_t t;

	gettimeofday(&time, NULL);

	t = ((time.tv_sec * 1000) + (time.tv_usec / 1000)) - philo->data->init_time;
	return (t);
}

void	ft_exit(t_data	*data)
{
	free(data->forks);
	free(data->philo);
	free(data->thread);
	free(data->died);
}
