/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:08:54 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/21 18:36:28 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				t_eat;
	int				t_sleep;
	int				n_t_must_eat;
	int				count_meal;
	int				finish_meal;
	time_t			last_meal;
}		t_philo;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_t_must_eat;
	int				n_t_must_eat_exists;
	int				die;
	int				print_die;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*died;
	pthread_mutex_t is_died;
	pthread_mutex_t	print;
	time_t			init_time;
}		t_data;

long int	ft_atoi(const char *nptr);
void		ft_init_all(t_data *data);
void		ft_statements(t_philo *philo);
time_t	ft_get_time_stamp(t_philo *philo);
time_t	ft_get_time(t_philo *philo);
void	ft_check_died(t_philo *philo, int i);
void	ft_print_died(t_philo *philo, int i);
void	ft_exit(t_data	*data);

#endif
