/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:36:05 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 23:49:25 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
