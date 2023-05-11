/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:08:58 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/11 12:28:21 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

/* 	struct timeval time;
	time_t tempo;

	gettimeofday(&time, NULL);

	tempo = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	printf("%ld", tempo); */

void	ft_initialize_data(t_data *data)
{
	data->n_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->n_times_must_eat = 0;
}

void	ft_get_value(t_data *data, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while(argv[i])
	{
		if (flag == 1)
			data->n_philo = ft_atoi(argv[i]);
		if (flag == 2)
			data->time_to_die = ft_atoi(argv[i]);
		if (flag == 3)
			data->time_to_eat = ft_atoi(argv[i]);
		if (flag == 4)
			data->time_to_sleep = ft_atoi(argv[i]);
		if (flag == 5)
			data->n_times_must_eat = ft_atoi(argv[i]);
		i++;
		flag++;
	}
}

int	main (int argc, char **argv)
{
	(void)argc;
	t_data	data;

	ft_initialize_data(&data);
	ft_get_value(&data, argv);
}
