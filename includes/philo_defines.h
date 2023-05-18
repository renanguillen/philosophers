/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/18 15:08:28 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEFINES_H
# define PHILO_DEFINES_H

// General
# define INT_MAX 2147483647
# define PHI_MAX 250
# define YES 0
# define NO 1

// Exit codes
# define CONTROL_OK 0
# define ERR_ARGS 1
# define ERR_MEMORY 2
# define ERR_MTX_INIT 3

// Exit messages
# define MSG_MEMORY "Error(2): Memory allocation failed.\n"
# define MSG_MTX_INIT "Error(3): Mutex initialization failed.\n"
#endif