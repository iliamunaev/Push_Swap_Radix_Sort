/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:36:05 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 17:19:11 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_arrs_arr(char ***arrs, int *arr)
{
	free_split_arrs(arrs);
	free(arr);
}

int	error_exit(t_stacks *stx)
{
	free_stx(stx);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	program_exit(t_stacks *stx, char ***arrs)
{
	free_stx(stx);
	free_split_arrs(arrs);
	exit(EXIT_SUCCESS);
}
