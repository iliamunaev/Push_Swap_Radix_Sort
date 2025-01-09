
#include "../include/push_swap.h"

void free_split_arrs(char ***arrs)
{
	int i = 0;
	int j;

	if (!arrs)
		return;

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
