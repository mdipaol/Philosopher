/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:08:58 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/06/02 16:22:43 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 	struct timeval time;
	time_t tempo;

	gettimeofday(&time, NULL);

	tempo = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	printf("%ld", tempo); */

void	ft_initialize_data(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	data->init_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	data->n_philo = 0;
	data->t_die = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
	data->n_t_must_eat = 0;
	data->n_t_must_eat_exists = 0;
	data->die = 0;
	data->print_die = 0;
}

void	ft_get_value(t_data *data, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (argv[i])
	{
		if (flag == 1)
			data->n_philo = ft_atoi(argv[i]);
		if (flag == 2)
			data->t_die = ft_atoi(argv[i]);
		if (flag == 3)
			data->t_eat = ft_atoi(argv[i]);
		if (flag == 4)
			data->t_sleep = ft_atoi(argv[i]);
		if (flag == 5)
		{
			data->n_t_must_eat = ft_atoi(argv[i]);
			if (data->n_t_must_eat)
				data->n_t_must_eat_exists = 1;
		}
		i++;
		flag++;
	}
}

int	ft_check_value(t_data *data)
{
	if (data->n_philo < 0)
		return (1);
	if (data->t_die < 0)
		return (1);
	if (data->t_eat < 0)
		return (1);
	if (data->t_sleep < 0)
		return (1);
	if (data->n_t_must_eat < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void) argc;
	ft_initialize_data(&data);
	ft_get_value(&data, argv);
	if (ft_check_value(&data))
		return (write(2, "Error, check inputs\n", 20));
	ft_init_all(&data);
}
