/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:37:04 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 23:42:59 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_sorted(t_stacks *stx)
{
	t_node *current;

	current = stx->a->head;

	while (current->next != stx->a->head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_index_position(t_stack *stack, int index)
{
	t_node *current;
	int position;

	position = 0;
	current = stack->head;
	while (current->index != index)
	{
		current = current->next;
		position++;
	}
	return (position);
}

int	find_min_index(t_stack *stack)
{
	t_node *current;
	int min_index;

	min_index = stack->head->index;
	current = stack->head->next;
	while (current != stack->head)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}
