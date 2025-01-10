/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:06:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:26:34 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stacks *stx)
{
	insert(stx->a, stx->b->head->value);
	stx->a->size++;
	stx->b->size--;
	stx->a->head->index = stx->b->head->index;
	pop(stx->b);
	ft_printf("pa\n");
}

void	pb(t_stacks *stx)
{
	insert(stx->b, stx->a->head->value);
	stx->b->size++;
	stx->a->size--;
	stx->b->head->index = stx->a->head->index;
	pop(stx->a);
	ft_printf("pb\n");
}

void	sa(t_stacks *stx)
{
	swap_nodes(stx->a);
	ft_printf("sa\n");
}

void	sb(t_stacks *stx)
{
	swap_nodes(stx->b);
	ft_printf("sb\n");
}
