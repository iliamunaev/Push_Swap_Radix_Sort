/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:18:35 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/13 11:32:56 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Performs one pass of radix sort on stack A.
 *
 * Moves elements from stack A to stack B based on the current bit (determined
 * by `shift`) of their indices. Elements with a 0 bit are moved to stack B,
 * and elements with a 1 bit remain in stack A.
 *
 * @param stx Pointer to the stack structure containing stacks A and B.
 * @param shift The bit position to evaluate for sorting.
 */
void	radix_sort_a(t_stacks *stx, int shift)
{
	int	size;

	size = stx->a->size;
	while (size > 0)
	{
		if (((stx->a->head->index >> shift) & 1) == 0)
			pb(stx);
		else
			ra(stx);
		size--;
	}
}

/**
 * @brief Performs one pass of radix sort on stack B.
 *
 * Moves elements back from stack B to stack A based on the current bit
 * (determined by `shift`) of their indices. Elements with a 0 bit are moved
 * to stack A, and elements with a 1 bit remain in stack B.
 *
 * @param stx Pointer to the stack structure containing stacks A and B.
 * @param shift The bit position to evaluate for sorting.
 */
void	radix_sort_b(t_stacks *stx, int shift)
{
	int	size;

	size = stx->b->size;
	while (size > 0)
	{
		if (((stx->b->head->index >> shift) & 0) == 0)
			pa(stx);
		else
			rb(stx);
		size--;
	}
}

/**
 * @brief Sorts the stacks using the radix sort algorithm.
 *
 * Repeatedly evaluates each bit of the indices of the elements in stack A,
 * moving them between stacks A and B to achieve a sorted order.
 *
 * @param stx Pointer to the stack structure containing stacks A and B.
 */
void	radix_sort(t_stacks *stx)
{
	int	shift;

	shift = 0;
	while (!is_sorted(stx))
	{
		radix_sort_a(stx, shift);
		radix_sort_b(stx, shift);
		shift++;
	}
}

/**
 * @brief Sorts the stack A based on its size using different algorithms.
 *
 * For small stacks (size 2 to 5), it uses specific sorting functions
 * (`sort_2`, `sort_3`, `sort_4_5`). For larger stacks, it applies the
 * radix sort algorithm.
 *
 * @param stx Pointer to the stack structure containing stacks A and B.
 */
void	sort(t_stacks *stx)
{
	if (stx->a->size == 2)
		sort_2(stx);
	else if (stx->a->size == 3)
		sort_3(stx);
	else if (stx->a->size >= 4 && stx->a->size <= 5)
		sort_4_5(stx);
	else
		radix_sort(stx);
}
