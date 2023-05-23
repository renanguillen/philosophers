/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/19 16:38:29 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEFINES_H
# define PHILO_DEFINES_H

// General
# define INT_MAX 2147483647
# define PHI_MAX 250
# define YES 1
# define NO 0

// Philosopher status
# define DEAD 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define FORK 4

// Exit codes
# define CONTROL_OK 0
# define ERR_ARGS 1
# define ERR_MEMORY 2
# define ERR_MTX_INIT 3
# define ERR_TRD_INIT 4

// Exit messages
# define MSG_MEMORY "Error(2): Memory allocation failed.\n"
# define MSG_MTX_INIT "Error(3): Mutex initialization failed.\n"
# define MSG_TRD_INIT "Error(4): Thread initialization failed.\n"
#endif