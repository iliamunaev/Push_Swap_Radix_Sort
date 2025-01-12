/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:34:26 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/12 12:15:44 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.h"

static t_node	*create_node(int x)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = x;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
void test_create_node()
{
	// Test 1: Valid input
	t_node *node = create_node(42);
	assert(node != NULL);
	assert(node->value == 42);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	free(node);

	// Test 2: Edge case - minimum value
	node = create_node(-2147483648); // INT_MIN
	assert(node != NULL);
	assert(node->value == -2147483648);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	free(node);

	// Test 3: Edge case - maximum value
	node = create_node(2147483647); // INT_MAX
	assert(node != NULL);
	assert(node->value == 2147483647);
	assert(node->next == NULL);
	assert(node->prev == NULL);
	free(node);

	printf("All tests for create_node passed successfully!\n");
}

int main()
{
	test_create_node();
	return 0;
}
