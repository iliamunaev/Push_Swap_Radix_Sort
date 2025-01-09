/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:06:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 19:12:06 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_nodes(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*old_prev_of_first;
	t_node	*old_next_of_second;

	if (stack->head->next->next == stack->head)
		stack->head = stack->head->next;
	else
	{
		first  = stack->head;
		second = first->next;
		old_prev_of_first  = first->prev;
		old_next_of_second = second->next;
		old_prev_of_first->next = second;
		second->prev = old_prev_of_first;
		second->next = first;
		first->prev  = second;
		first->next	 = old_next_of_second;
		old_next_of_second->prev = first;
		stack->head = second;
	}
}

static void pop(t_stack *stack)
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

static t_node	*insert(t_stack *stack, int value)
{
	stack->head = insert_num(stack->head, value);
	return (stack->head);
}

// Comands ------------------------------

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
/*
void	ss(t_stacks *stx)
{
	sa(stx);
	sb(stx);
	ft_putendl_fd("ss", 1);
}

void	rrr(t_stacks *stx)
{
	rra(stx->stack_a);
	rrb(stx->stack_b);
	ft_putendl_fd("rrr", 1);
}


void	rr(t_stacks *stx)
{
	ra(stx->stack_a);
	rb(stx->stack_b);
	ft_putendl_fd("rr", 1);
}
*/
