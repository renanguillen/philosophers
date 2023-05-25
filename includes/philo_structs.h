/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:11:34 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

typedef struct s_philosopher	t_philosopher;

typedef struct s_simulation
{
	time_t			start_time;
	unsigned int	how_many;
	pthread_t		observer;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat_count;
	int				stop_flag;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*fork_mutexes;
	t_philosopher	**philos;
}	t_simulation;

typedef struct s_philosopher
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		eaten;
	unsigned int		fork[2];
	pthread_mutex_t		meal_mutex;
	time_t				last_meal;
	t_simulation		*simulation;
}	t_philosopher;

#endif