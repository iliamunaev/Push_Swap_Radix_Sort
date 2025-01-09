#include "test_utils.h"

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

void test_insert_num()
{
	// Test 1: Insert into an empty list
	t_node *head = NULL;
	head = insert_num(head, 42);
	assert(head != NULL);
	assert(head->value == 42);
	assert(head->next == head);
	assert(head->prev == head);

	// Test 2: Insert into a non-empty list
	head = insert_num(head, 84);
	assert(head != NULL);
	assert(head->value == 84);
	assert(head->next->value == 42);
	assert(head->prev->value == 42);
	assert(head->next->prev == head);
	assert(head->prev->next == head);

	// Test 3: Insert multiple elements
	head = insert_num(head, 168);
	assert(head->value == 168);
	assert(head->next->value == 84);
	assert(head->prev->value == 42);
	assert(head->next->prev == head);
	assert(head->prev->next == head);

	printf("All tests for insert_num passed successfully!\n");
}

int main()
{
	test_insert_num();
	return 0;
}
