/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:12 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/13 12:00:58 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Sorts a stack with two elements.
 *
 * If the two elements in stack A are not in ascending order, swaps them.
 *
 * @param stx Pointer to the stack structure containing stack A.
 */
void	sort_2(t_stacks *stx)
{
	if (stx->a->head->value > stx->a->head->next->value)
		sa(stx);
}

/**
 * @brief Sorts a stack with three elements.
 *
 * Determines the order of the three elements in stack A and applies the
 * appropriate operations to sort them in ascending order.
 *
 * @param stx Pointer to the stack structure containing stack A.
 */
void	sort_3(t_stacks *stx)
{
	int	first;
	int	second;
	int	third;

	first = stx->a->head->value;
	second = stx->a->head->next->value;
	third = stx->a->head->next->next->value;
	if (first > second && second > third)
	{
		sa(stx);
		rra(stx);
	}
	else if (first > second && first > third && second < third)
		ra(stx);
	else if (first < second && first > third && second > third)
		rra(stx);
	else if (first > second && first < third && second < third)
		sa(stx);
	else if (first < second && first < third && second > third)
	{
		rra(stx);
		sa(stx);
	}
}

/**
 * @brief Sorts a stack with four or five elements.
 *
 * Repeatedly moves the smallest element from stack A to stack B until stack A
 * has three elements, sorts the remaining elements in stack A, and then moves
 * the elements back from stack B to stack A in sorted order.
 *
 * @param stx Pointer to the stack structure containing stacks A and B.
 */
void	sort_4_5(t_stacks *stx)
{
	int	min_index;

	while (stx->a->size > 3)
	{
		min_index = find_min_index(stx->a);
		while (stx->a->head->index != min_index)
		{
			if (get_index_position(stx->a, min_index) <= stx->a->size / 2)
				ra(stx);
			else
				rra(stx);
		}
		pb(stx);
	}
	sort_3(stx);
	while (stx->b->size > 0)
		pa(stx);
}
