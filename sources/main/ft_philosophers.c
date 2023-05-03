/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:17:03 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/03 17:08:18 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static t_data	*ft_initialize_data(int argc, char **argv)
{
	t_data	*philo;

	(void)argc;
	(void)argv;
	philo = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!philo)
		return (NULL);
	return (philo);
}

int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	*philo;

	exit_code = ft_check_arguments(argc, argv);
	if (exit_code)
	{
		ft_print_error(exit_code);
		return (exit_code);
	}
	philo = ft_initialize_data(argc, argv);
	return (exit_code);
}
