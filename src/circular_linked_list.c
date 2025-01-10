/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_circular_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:37:59 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:41:33 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
