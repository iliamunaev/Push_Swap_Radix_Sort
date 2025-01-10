/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:49:30 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 17:11:56 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stacks	*creat_stacks(void)
{
	t_stacks	*stx;

	stx = malloc(sizeof(t_stacks));
	if (!stx)
		return (NULL);
	stx->a = NULL;
	stx->b = NULL;
	stx->a = malloc(sizeof(t_stack));
	if (!stx->a)
		error_exit(stx);
	stx->a->head = NULL;
	stx->a->size = 0;
	stx->b = malloc(sizeof(t_stack));
	if (!stx->b)
		error_exit(stx);
	stx->b->head = NULL;
	stx->b->size = 0;
	return (stx);
}

t_stacks	*init_stack(int ac, char **av)
{
	int			*arr;
	int			size;
	t_stacks	*stx;
	char		***arrs;

	stx = creat_stacks();
	arrs = split_arrs(ac, av);
	if (!arrs)
		error_exit(stx);
	size = get_len_arr(arrs);
	if (size == 0 || size == 1)
		program_exit(stx, arrs);
	if (size > 10000)
	{
		free_split_arrs(arrs);
		error_exit(stx);
	}
	arr = get_int_arr(size, arrs);
	if (!arr)
		error_exit(stx);
	if (is_duplicate(arr, size))
		error_exit(stx);
	stx = fill_up_stack(stx, arr, size);
	free(arr);
	return (stx);
}
