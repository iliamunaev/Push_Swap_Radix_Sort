
#include "../include/push_swap.h"
#include <stdio.h>

int	assign_index(t_stacks *stx)
{
	printf("here!\n");

	if(!stx)
		printf("fail!\n");
	printf("good!\n");

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

