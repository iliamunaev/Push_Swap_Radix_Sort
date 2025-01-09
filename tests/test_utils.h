#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Node structure for doubly circular linked list
typedef struct s_node
{
	int			 value;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

// Stack structure
typedef struct s_stack
{
	t_node	*head;
	int	size;
} t_stack;

// Stacks for A and B
typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
} t_stacks;

#endif
