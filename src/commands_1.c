/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:06:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:27:59 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stacks *stx)
{
	stx->a->head = stx->a->head->next;
	ft_printf("ra\n");
}

void	rb(t_stacks *stx)
{
	stx->b->head = stx->b->head->next;
	ft_printf("rb\n");
}

void	rra(t_stacks *stx)
{
	stx->a->head = stx->a->head->prev;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stx)
{
	stx->b->head = stx->b->head->prev;
	ft_printf("rrb\n");
}
