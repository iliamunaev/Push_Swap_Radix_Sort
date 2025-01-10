/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:37:59 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/11 00:08:28 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Creates a new node for a circular doubly linked list.
 *
 * Allocates memory for a new node, initializes its value and index, and
 * sets its `next` and `prev` pointers to NULL.
 *
 * @param x The value to store in the new node.
 * @return t_node* Pointer to the newly created node, or NULL on failure.
 */
static t_node	*create_node(int x)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = x;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * @brief Inserts a new node with a given value into
 * a circular doubly linked list.
 *
 * If the list is empty, the new node becomes the head,
 * and its `next` and `prev`
 * pointers reference itself. Otherwise, the node is added
 * before the current head.
 *
 * @param head The current head of the circular doubly linked list.
 * @param value The value to store in the new node.
 * @return t_node* Pointer to the new node (new head), or NULL on failure.
 */
t_node	*insert_num(t_node *head, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(value);
	if (!new_node)
		return (NULL);
	if (!head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	last = head->prev;
	new_node->next = head;
	new_node->prev = last;
	last->next = new_node;
	head->prev = new_node;
	return (new_node);
}

/**
 * @brief Populates stack A with values from an array.
 *
 * Inserts values from the provided array into stack A in reverse order
 * to maintain the correct sequence. Updates the stack's size accordingly.
 *
 * @param stx Pointer to the stacks structure.
 * @param arr Array of integers to populate stack A.
 * @param size The size of the array.
 * @return t_stacks* Pointer to the updated stacks structure.
 */
t_stacks	*fill_up_stack(t_stacks *stx, int *arr, int size)
{
	size--;
	while (size >= 0)
	{
		stx->a->head = insert_num(stx->a->head, arr[size]);
		if (!stx->a->head)
			error_exit(stx);
		stx->a->size++;
		size--;
	}
	return (stx);
}
