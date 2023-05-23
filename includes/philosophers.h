/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:42:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/23 18:53:45 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "philo_structs.h"
# include "philo_defines.h"

// MAIN

void	action_eat(t_philosopher *philo);
void	action_sleep(t_philosopher *philo);
void	action_think(t_philosopher *philosopher, int should_print);
void	action_wait(t_simulation *simulation, time_t wait_time);
void	allign_start_times(time_t start_time);
int		check_arguments(int argc, char **argv);
int		exit_handler(t_simulation *simulation, char *print_this, int exit_code);
int		init_simulation(t_simulation *simulation, int argc, char **argv);
int		init_table(t_simulation *simulation);
int		is_it_over(t_simulation *simulation);
void	*observer_routine(void *argument);
void	*philosopher_routine(void *argument);
void	print_status(t_philosopher *philosopher, int observer, int status);
int		simulate(t_simulation *simulation);
int		stop_simulation(t_simulation *simulation);

// TOOLS

int		ft_atoi(const char *string);
void	*ft_calloc(size_t num_elements, size_t element_size);
time_t	ft_fetch_time(void);
void	ft_free_pointer(void **pointer);
void	ft_free_ppointer(void ***ppointer);
int		ft_onlydigits(char *value);

#endif