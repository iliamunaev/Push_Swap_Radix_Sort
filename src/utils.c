/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:22:00 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 11:34:48 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_arrs(char ***arrs)
{
	int	i;
	int	j;

	if (!arrs)
		return ;
	i = 0;
	while (arrs[i] != NULL)
	{
		j = 0;
		while (arrs[i][j] != NULL)
		{
			free(arrs[i][j]);
			j++;
		}
		free(arrs[i]);
		i++;
	}
	free(arrs);
}
void	free_circular_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	if (!head)
		return ;
	current = head;
	next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		if (next == head)
			break ;
		current = next;
	}
}
void	free_stx(t_stacks *stx)
{
	if (!stx || ! stx->a || !stx->b)
		return ;
	if (stx->a)
	{
		if (stx->a->head)
			free_circular_list(stx->a->head);
		free(stx->a);
		stx->a = NULL;
	}
	if (stx->b)
	{
		if (stx->b->head)
			free_circular_list(stx->b->head);
		free(stx->b);
		stx->b = NULL;
	}
	free(stx);
	stx = NULL;
}
