/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:42:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/28 13:47:33 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int				id;
	int				eat_count;
	int				last_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
}	t_philosopher;

typedef struct s_data
{
	int						philo_count;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						must_eat_count;
	int						dead;
	int						finished;
	int						start_time;
	pthread_mutex_t			*forks;
	pthread_mutex_t			print;
	t_philosopher			*philosophers;
}	t_data;


#endif