/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:12 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:48:13 by imunaev-         ###   ########.fr       */
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
