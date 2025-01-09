#include "test_utils.h"

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

t_node	*create_node(int x)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = x;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node *insert_num(t_node *head, int value)
{
	t_node *new_node;
	t_node *last;

	new_node = create_node(value);
	if (!new_node)
		return (NULL);
	if (!head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	last = head->prev;
	new_node->next = head;
	new_node->prev = last;
	last->next = new_node;
	head->prev = new_node;
	return (new_node);
}

t_stacks	*fill_up_stack(t_stacks *stx, int *arr, int size)
{
	stx->a->size = size;
	size--;

	while (size >= 0)
	{
		stx->a->head = insert_num(stx->a->head, arr[size]);
		if (!stx->a->head)
		{
			free_stx(stx);
			return (NULL);
		}
		size--;
	}
	return (stx);
}

void test_fill_up_stack()
{
	// Test 1: Fill up stack with valid input
	int arr[] = {1, 2, 3, 4, 5};
	t_stacks *stx = malloc(sizeof(t_stacks));
	stx->a = malloc(sizeof(t_stack));
	stx->a->head = NULL;
	stx->a->size = 0;
	stx->b = NULL;

	stx = fill_up_stack(stx, arr, 5);
	assert(stx != NULL);
	assert(stx->a->size == 5);

	t_node *current = stx->a->head;
	assert(current->value == 1); current = current->next;
	assert(current->value == 2); current = current->next;
	assert(current->value == 3); current = current->next;
	assert(current->value == 4); current = current->next;
	assert(current->value == 5);

	free_stx(stx);

	printf("All tests for fill_up_stack passed successfully!\n");
}

int main()
{
	test_fill_up_stack();
	return 0;
}
