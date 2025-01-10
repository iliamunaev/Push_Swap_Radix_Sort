/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:18:35 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:48:03 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
