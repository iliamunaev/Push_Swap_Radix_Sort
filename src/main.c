/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:41:39 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:21:02 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	stx = init_stack(ac - 1, av + 1);
	assign_index(stx);
	if (!is_sorted(stx))
		sort(stx);
	free_stx(stx);
	return (EXIT_SUCCESS);
}
