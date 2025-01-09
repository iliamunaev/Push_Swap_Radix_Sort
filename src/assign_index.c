/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:47:28 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 18:47:30 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	assign_index(t_stacks *stx)
{
	t_node *current;
	t_node *compare;

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
				break;
		}
		current = current->next;
		if (current == stx->a->head)
			break;
	}
	return (1);
}

