/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:06:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 23:56:26 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Pushes the top element from stack B to stack A.
 *
 * Removes the top element from stack B, inserts it into stack A, and updates
 * the sizes and indices of the stacks accordingly.
 *
 * @param stx Pointer to the stack structure containing stacks A and B.
 */
void	pa(t_stacks *stx)
{
	insert(stx->a, stx->b->head->value);
	stx->a->size++;
	stx->b->size--;
	stx->a->head->index = stx->b->head->index;
	pop(stx->b);
	ft_printf("pa\n");
}

/**
 * @brief Pushes the top element from stack A to stack B.
 *
 * Removes the top element from stack A, inserts it into stack B, and updates
 * the sizes and indices of the stacks accordingly.
 *
 * @param stx Pointer to the stack structure containing stacks A and B.
 */
void	pb(t_stacks *stx)
{
	insert(stx->b, stx->a->head->value);
	stx->b->size++;
	stx->a->size--;
	stx->b->head->index = stx->a->head->index;
	pop(stx->a);
	ft_printf("pb\n");
}

/**
 * @brief Swaps the first two elements of stack A.
 *
 * Reorders the first two elements of stack A by modifying the node pointers
 * in the circular doubly linked list.
 *
 * @param stx Pointer to the stack structure containing stack A.
 */
void	sa(t_stacks *stx)
{
	swap_nodes(stx->a);
	ft_printf("sa\n");
}

/**
 * @brief Swaps the first two elements of stack B.
 *
 * Reorders the first two elements of stack B by modifying the node pointers
 * in the circular doubly linked list.
 *
 * @param stx Pointer to the stack structure containing stack B.
 */
void	sb(t_stacks *stx)
{
	swap_nodes(stx->b);
	ft_printf("sb\n");
}
