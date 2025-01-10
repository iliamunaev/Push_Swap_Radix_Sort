/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:22:55 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 23:54:21 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Swaps the first two nodes in a circular doubly linked list.
 *
 * This function modifies the pointers of the first two nodes in the stack
 * to swap their positions while maintaining the circular doubly linked
 * list structure. If the stack has only two nodes, the head pointer is updated.
 *
 * @param stack The stack on which the operation is performed.
 */
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

/**
 * @brief Removes the first node from the stack.
 *
 * This function frees the memory of the node at the head of the stack
 * and updates the head pointer and other links to maintain the circular
 * doubly linked list structure. If the stack has only one node, the stack
 * becomes empty.
 *
 * @param stack The stack from which the node is removed.
 */
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

/**
 * @brief Inserts a new node with the given value into the stack.
 *
 * This function inserts a new node with the specified value into the
 * circular doubly linked list at the head of the stack.
 *
 * @param stack The stack where the new node is inserted.
 * @param value The value to insert into the stack.
 * @return t_node* Pointer to the new head of the stack.
 */
t_node	*insert(t_stack *stack, int value)
{
	stack->head = insert_num(stack->head, value);
	return (stack->head);
}
