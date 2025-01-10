/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 23:37:04 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/11 00:00:51 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks if stack A is sorted in ascending order.
 *
 * Iterates through stack A and verifies whether all the values are in ascending
 * order. Returns 1 if the stack is sorted, 0 otherwise.
 *
 * @param stx Pointer to the stack structure containing stack A.
 * @return int 1 if stack A is sorted, 0 otherwise.
 */
int	is_sorted(t_stacks *stx)
{
	t_node	*current;

	current = stx->a->head;
	while (current->next != stx->a->head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/**
 * @brief Finds the position of a node with a specific index in a stack.
 *
 * Iterates through the stack to locate the node with the specified index.
 * Returns the 0-based position of the node in the stack.
 *
 * @param stack Pointer to the stack to search.
 * @param index The index to find.
 * @return int The position of the node with the specified index.
 */
int	get_index_position(t_stack *stack, int index)
{
	t_node	*current;
	int		position;

	position = 0;
	current = stack->head;
	while (current->index != index)
	{
		current = current->next;
		position++;
	}
	return (position);
}

/**
 * @brief Finds the smallest index in a stack.
 *
 * Iterates through the stack and returns the smallest index value among
 * the nodes in the stack.
 *
 * @param stack Pointer to the stack to search.
 * @return int The smallest index in the stack.
 */
int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;

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
