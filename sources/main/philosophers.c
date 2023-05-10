/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:17:03 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 17:11:00 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

// int	primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

// void	*routine(void *arg)
// {
// 	int index = *(int*)arg;
// 	printf("%d\n", index);
// 	return (NULL);
// }
/*
* Main function of the program.

* Returns the exit code after deallocating the memory.
*/
int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	*memory;
	pthread_t threads[10];
	int i = 0;

	exit_code = check_arguments(argc, argv);
	if (exit_code)
		return (exit_code);
	memory = initialize_memory(argc, argv);
	//threadtest
	// while (i < 10)
	// {
	// 	if (pthread_create(&threads[i], NULL, &routine, primes+i) != 0)
	// 		perror("Failed to create thread");
	// 	i++;
	// }
	// i = 0;
	// while (i < 10)
	// {
	// 	if (pthread_join(threads[i], NULL) != 0)
	// 		perror("Failed to join thread");
	// 	i++;
	// }
	//return to normal
	return (deallocate_memory(memory));
}
