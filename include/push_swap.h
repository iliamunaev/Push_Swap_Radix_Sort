/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:40:14 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/13 11:38:30 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# define VALUE_ERROR LONG_MAX

// Validation context for input strings
typedef struct s_valid_ctx
{
	int		i;				// Current position in the string.
	bool	in_number;		// Flag to indicate if currently in a number.
	bool	leading_zero;	// Flag for leading zeros in a number.
	int		found_digit;	// Indicates if at least one digit was found.
}	t_valid_ctx;

// Node structure for the circular doubly linked list
typedef struct s_node
{
	int				value;	// Value stored in the node.
	int				index;	// Index assigned during sorting.
	struct s_node	*prev;	// Pointer to the previous node.
	struct s_node	*next;	// Pointer to the next node.
}	t_node;

// Stack structure containing a circular doubly linked list and its size
typedef struct s_stack
{
	t_node	*head;	// Pointer to the head of the stack.
	int		size;	// Number of nodes in the stack.
}	t_stack;

// Structure containing both stacks A and B
typedef struct s_stacks
{
	t_stack	*a;	// Pointer to stack A.
	t_stack	*b;	// Pointer to stack B.
}	t_stacks;

// Utility for searching specific values in the stack
typedef struct s_find_number
{
	int		value;	// Value being searched.
	bool	found;	// Indicates if the value was found.
}	t_find_number;

// validation functions
int			validate_input(int ac, char **av);
int			is_sorted(t_stacks *stx);
int			ft_issign(char c);
int			ft_isspace(char c);
bool		is_duplicate(int *arr, int size);
bool		skip_initial_spaces(const char *s, t_valid_ctx *ctx);
bool		handle_sign(const char *s, t_valid_ctx *ctx);
bool		handle_sign(const char *s, t_valid_ctx *ctx);
bool		handle_digit(const char *s, t_valid_ctx *ctx);
void		handle_spaces_in_middle(const char *s, t_valid_ctx *ctx);

// init arr and stacks functions
t_stacks	*init_stack(int ac, char **av);
char		***split_arrs(int ac, char **av);
int			get_len_arr(char ***arrs);
int			*get_int_arr(int size, char ***arrs);
t_stacks	*fill_up_stack(t_stacks *stx, int *arr, int size);
t_node		*insert_num(t_node *head, int value);
void		assign_index(t_stacks *stx);

// commands
void		ra(t_stacks *stx);
void		rb(t_stacks *stx);
void		rra(t_stacks *stx);
void		rrb(t_stacks *stx);
void		pa(t_stacks *stx);
void		pb(t_stacks *stx);
void		sa(t_stacks *stx);
void		sb(t_stacks *stx);

// comand utils
void		swap_nodes(t_stack *stack);
void		pop(t_stack *stack);
t_node		*insert(t_stack *stack, int value);

// sort function
void		sort(t_stacks *stx);
void		sort_2(t_stacks *stx);
void		sort_3(t_stacks *s);
void		sort_4_5(t_stacks *s);
void		radix_sort(t_stacks *stx);
void		radix_sort_a(t_stacks *stx, int shift);
void		radix_sort_b(t_stacks *stx, int shift);
int			get_index_position(t_stack *stack, int index);
int			find_min_index(t_stack *stack);

//memory free and exit function
void		free_arrs_arr(char ***arrs, int *arr);
void		free_split_arrs(char ***arrs);
void		free_circular_list(t_node *head);
void		free_stx(t_stacks *stx);
int			error_exit(t_stacks *stx);
int			program_exit(t_stacks *stx, char ***arrs);

// tests
// void print_test_stack(t_stacks *stx);
// #include <stdio.h>

#endif
