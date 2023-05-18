/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:42:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/18 15:39:46 by ridalgo-         ###   ########.fr       */
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
int		check_arguments(int argc, char **argv);
int		exit_handler(t_simulation *simulation, char *print_this, int exit_code);
int		init_table(t_simulation *simulation);
int		init_simulation(t_simulation *simulation, int argc, char **argv);

// TOOLS
int		ft_atoi(const char *string);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	ft_free_pointer(void **pointer);
void	ft_free_ppointer(void ***ppointer);
int		ft_onlydigits(char *value);

#endif