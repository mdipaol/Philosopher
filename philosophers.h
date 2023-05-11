/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:08:54 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/11 22:44:30 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				t_eat;
	int				t_sleep;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*mutex_print;
}		t_philo;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_t_must_eat;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	time_t			init_time;
}		t_data;

long int	ft_atoi(const char *nptr);
void		ft_init_all(t_data *data);
void		ft_statements(t_data *data);

#endif
