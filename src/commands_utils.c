/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:22:55 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:28:58 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_nodes(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*old_prev_of_first;
	t_node	*old_next_of_second;

	if (stack->head->next->next == stack->head)
		stack->head = stack->head->next;
	else
	{
		first = stack->head;
		second = first->next;
		old_prev_of_first = first->prev;
		old_next_of_second = second->next;
		old_prev_of_first->next = second;
		second->prev = old_prev_of_first;
		second->next = first;
		first->prev = second;
		first->next = old_next_of_second;
		old_next_of_second->prev = first;
		stack->head = second;
	}
}

void	pop(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	if (node->next == node && node->prev == node)
	{
		stack->head = NULL;
		free(node);
		return ;
	}
	node->next->prev = node->prev;
	node->prev->next = node->next;
	if (stack->head == node)
		stack->head = node->next;
	free(node);
}

t_node	*insert(t_stack *stack, int value)
{
	stack->head = insert_num(stack->head, value);
	return (stack->head);
}
