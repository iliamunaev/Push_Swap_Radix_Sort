/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:47:28 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/11 00:09:19 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Assigns an index to each node in stack A based on its value.
 *
 * This function iterates through the nodes of stack A and assigns an index
 * to each node based on the number of nodes with smaller values. The smallest
 * value receives an index of 0, and
 * the largest value receives the highest index.
 *
 * The process involves comparing each node's value with every other node's
 * value in the stack using a nested loop, ensuring a circular traversal.
 *
 * @param stx Pointer to the stacks structure containing stack A.
 */
void	assign_index(t_stacks *stx)
{
	t_node	*current;
	t_node	*compare;

	current = stx->a->head;
	while (1)
	{
		compare = stx->a->head;
		while (1)
		{
			if (current->value > compare->value)
				current->index++;
			compare = compare->next;
			if (compare == stx->a->head)
				break ;
		}
		current = current->next;
		if (current == stx->a->head)
			break ;
	}
	return ;
}
