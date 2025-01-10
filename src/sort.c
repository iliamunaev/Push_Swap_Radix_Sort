/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:18:35 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 10:20:34 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_stacks *stx)
{
	if (stx->a->head->value > stx->a->head->next->value)
		sa(stx);
}

void	sort_3(t_stacks *stx)
{
	int first = stx->a->head->value;
	int second = stx->a->head->next->value;
	int third = stx->a->head->next->next->value;

	if (first > second && second > third)
	{
		sa(stx);
		rra(stx);
	}
	else if (first > second && first > third && second < third)
		ra(stx);
	else if (first < second && first > third && second > third)
	{
		sa(stx);
		ra(stx);
	}
	else if (first > second && first < third && second < third)
		sa(stx);
	else if (first < second && second > third && first < third)
		rra(stx);
}

void	sort_4_5(t_stacks *stx)
{
	int min_index;

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

void	radix_sort_a(t_stacks *stx, int shift)
{
	int	size;

	size = stx->a->size;
	while (size > 0)
	{
		if(((stx->a->head->index >> shift) & 1) == 0)
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
		if(((stx->b->head->index >> shift) & 0) == 0)
			pa(stx);
		else
			rb(stx);
		size--;
	}
}

void	radix_sort(t_stacks *stx)
{
	int shift;

	shift = 0;
	while(!is_sorted(stx))
	{
		radix_sort_a(stx, shift);
		radix_sort_b(stx, shift);
		shift++;
	}
}

void sort(t_stacks *stx)
{
	if(stx->a->size == 2)
		sort_2(stx);
	else if(stx->a->size == 3)
		sort_3(stx);
	else if(stx->a->size >= 4 &&  stx->a->size <= 5)
		sort_4_5(stx);
	else
		radix_sort(stx);
}
