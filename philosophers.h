/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:08:54 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/05/11 15:41:36 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	int	id;
	t_eat;
	t_sleep;

}		t_philo;

typedef struct s_data
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_t_must_eat;
	t_philo	*philo;
	pthread_t *thread;
	pthread_mutex_t *mutex;
	int	*forks;
}		t_data;

long int	ft_atoi(const char *nptr);
void	ft_init_all(t_data *data);
