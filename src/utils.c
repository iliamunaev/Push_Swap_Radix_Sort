/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:35:54 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 15:01:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_isspace(char c)
{
	return (c == ' '
		|| c == '\n'
		|| c == '\f'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v'
	);
}

void	free_split_arrs(char ***arrs)
{
	int	i;
	int	j;

	i = 0;
	if (!arrs)
		return ;
	while (arrs[i])
	{
		if (arrs[i] != NULL)
		{
			j = 0;
			while (arrs[i][j] != NULL)
			{
				free(arrs[i][j]);
				arrs[i][j] = NULL;
				j++;
			}
			free(arrs[i]);
			arrs[i] = NULL;
		}
		i++;
	}
	free(arrs);
	arrs = NULL;
}

void	free_circular_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	if (!head)
		return ;
	current = head->next;
	while (current != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(head);
}

void	free_stx(t_stacks *stx)
{
	if (!stx)
		return ;
	if (stx->a)
	{
		if (stx->a->head)
			free_circular_list(stx->a->head);
		free(stx->a);
	}
	if (stx->b)
	{
		if (stx->b->head)
			free_circular_list(stx->b->head);
		free(stx->b);
	}
	free(stx);
}
