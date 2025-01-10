/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:06:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 23:55:15 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Rotates stack A upwards.
 *
 * Moves the first node of stack A to the end of the stack by updating the
 * head pointer to the next node in the circular doubly linked list.
 *
 * @param stx Pointer to the stack structure containing stack A.
 */
void	ra(t_stacks *stx)
{
	stx->a->head = stx->a->head->next;
	ft_printf("ra\n");
}

/**
 * @brief Rotates stack B upwards.
 *
 * Moves the first node of stack B to the end of the stack by updating the
 * head pointer to the next node in the circular doubly linked list.
 *
 * @param stx Pointer to the stack structure containing stack B.
 */
void	rb(t_stacks *stx)
{
	stx->b->head = stx->b->head->next;
	ft_printf("rb\n");
}

/**
 * @brief Rotates stack A downwards.
 *
 * Moves the last node of stack A to the beginning of the stack by updating the
 * head pointer to the previous node in the circular doubly linked list.
 *
 * @param stx Pointer to the stack structure containing stack A.
 */
void	rra(t_stacks *stx)
{
	stx->a->head = stx->a->head->prev;
	ft_printf("rra\n");
}

/**
 * @brief Rotates stack B downwards.
 *
 * Moves the last node of stack B to the beginning of the stack by updating the
 * head pointer to the previous node in the circular doubly linked list.
 *
 * @param stx Pointer to the stack structure containing stack B.
 */
void	rrb(t_stacks *stx)
{
	stx->b->head = stx->b->head->prev;
	ft_printf("rrb\n");
}
