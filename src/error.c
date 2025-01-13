/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:36:05 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/13 18:31:16 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Frees a 3D array of strings and an integer array.
 *
 * This function releases the memory allocated for a split array of strings
 * and an integer array.
 *
 * @param arrs The 3D array of strings to free.
 * @param arr The integer array to free.
 */
void	free_arrs_arr(char ***arrs, int *arr)
{
	free_split_arrs(arrs);
	free(arr);
}

/**
 * @brief Exits the program with an error message.
 *
 * Frees the allocated memory for the stacks and prints "Error" to standard
 * error before exiting the program with `EXIT_FAILURE`.
 *
 * @param stx The stack structure to free.
 * @return int Always returns `EXIT_FAILURE`.
 */
int	error_exit(t_stacks *stx)
{
	free_stx(stx);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief Exits the program successfully after cleanup.
 *
 * Frees the allocated memory for the stacks and split arrays, then exits the
 * program with `EXIT_SUCCESS`.
 *
 * @param stx The stack structure to free.
 * @param arrs The 3D array of strings to free.
 * @return int Always returns `EXIT_SUCCESS`.
 */
int	program_exit(t_stacks *stx, char ***arrs)
{
	free_stx(stx);
	free_split_arrs(arrs);
	exit(EXIT_FAILURE);
}
