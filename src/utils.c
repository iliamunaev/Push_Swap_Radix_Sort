/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:35:54 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 23:59:11 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks if a character is a sign ('-' or '+').
 *
 * @param c The character to check.
 * @return int 1 if the character is a sign, 0 otherwise.
 */
int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

/**
 * @brief Checks if a character is a whitespace character.
 *
 * Whitespace characters include space, newline, form feed, carriage return,
 * tab, and vertical tab.
 *
 * @param c The character to check.
 * @return int 1 if the character is a whitespace, 0 otherwise.
 */
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

/**
 * @brief Frees a 3D array of strings.
 *
 * This function iterates through a 3D array and frees all allocated memory
 * for each string and sub-array before freeing the array itself.
 *
 * @param arrs The 3D array to free.
 */
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

/**
 * @brief Frees all nodes in a circular doubly linked list.
 *
 * This function iterates through a circular doubly linked list and frees
 * all nodes, ensuring that memory is properly released.
 *
 * @param head The head of the circular linked list.
 */
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

/**
 * @brief Frees all memory allocated for the stack structure.
 *
 * This function frees the circular linked lists and any memory allocated
 * for the stacks `a` and `b` within the `t_stacks` structure.
 *
 * @param stx The stack structure to free.
 */
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
