/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:11:34 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/03 17:12:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

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
	int						exit_code;
	pthread_mutex_t			*forks;
	pthread_mutex_t			print;
	t_philosopher			*philosophers;
}	t_data;

#endif