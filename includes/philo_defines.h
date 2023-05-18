/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/17 23:11:13 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEFINES_H
# define PHILO_DEFINES_H

// General
# define INT_MAX 2147483647
# define PHI_MAX 250
# define YES 0
# define NO 1

// Argument indexes
# define ERR_ARG_COUNT 1
# define ERR_PHILO_COUNT 2
# define ERR_TTD 3
# define ERR_TTE 4
# define ERR_TTS 5
# define ERR_EAT_COUNT 6

// Exit codes
# define CHECK_OK 0
# define ERR_ARGS 1
# define ERR_MEMORY 2
# define ERR_THREAD 3
# define ERR_MUTEX 4
#endif