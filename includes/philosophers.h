/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:42:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/03 17:15:06 by ridalgo-         ###   ########.fr       */
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
// TOOLS

int		ft_atoi(const char *string);
void	*ft_calloc(size_t num_elements, size_t element_size);
int		ft_check_arguments(int argc, char **argv);
void	ft_print_error(int exit_code);
#endif