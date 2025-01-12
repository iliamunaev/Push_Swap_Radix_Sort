/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:41:39 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/12 11:46:59 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Main entry point of the program.
 *
 * This function validates the input arguments, initializes the stack,
 * assigns indices to the stack elements, checks if the stack is already
 * sorted, and sorts it if necessary. Finally, it frees allocated memory.
 *
 * @param ac The argument count.
 * @param av The array of argument strings.
 * @return int EXIT_SUCCESS (0) if the program completes successfully,
 *         or EXIT_FAILURE (1) if an error occurs.
 */
int	main(int ac, char **av)
{
	t_stacks	*stx;

	if (ac < 2)
		return (EXIT_FAILURE);
	if (!validate_input(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	stx = init_stack(ac, av);
	assign_index(stx);
	if (!is_sorted(stx))
		sort(stx);
	free_stx(stx);
	return (EXIT_SUCCESS);
}
