/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:49:30 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 23:51:08 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Allocates and initializes the stack structures for the program.
 *
 * This function creates and allocates memory for the `t_stacks` structure,
 * which includes two stacks (`a` and `b`). It initializes their size and
 * head pointers. If any allocation fails, it exits the program with an error.
 *
 * @return t_stacks* Pointer to the newly created stack structure.
 *                   Returns NULL if memory allocation fails.
 */
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

/**
 * @brief Initializes and populates the stack structure with input data.
 *
 * This function validates and processes the input arguments, splits them into
 * arrays, converts them to integers, and checks for duplicates. It then fills
 * up the `a` stack in the `t_stacks` structure. If any errors occur during
 * validation or memory allocation, the program exits.
 *
 * @param ac The number of input arguments.
 * @param av The array of input argument strings.
 * @return t_stacks* Pointer to the initialized and populated stack structure.
 */
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
