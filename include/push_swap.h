/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:40:14 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 17:18:06 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# define VALUE_ERROR LONG_MAX

typedef struct s_valid_ctx
{
	int		i;
	bool	in_number;
	bool	leading_zero;
	int		found_digit;
}	t_valid_ctx;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_find_number
{
	int		value;
	bool	found;
}	t_find_number;

t_stacks	*init_stack(int ac, char **av);
char		***split_arrs(int ac, char **av);
int			get_len_arr(char ***arrs);
int			*get_int_arr(int size, char ***arrs);
t_stacks	*fill_up_stack(t_stacks *stx, int *arr, int size);
void		free_circular_list(t_node *head);
void		free_stx(t_stacks *stx);
t_node		*insert_num(t_node *head, int value);
void		free_split_arrs(char ***arrs);
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

int			validate_input(int ac, char **av);
int			is_sorted(t_stacks *stx);
int			ft_issign(char c);
int			ft_isspace(char c);
int			is_duplicate(int *arr, int size);
bool		skip_initial_spaces(const char *s, t_valid_ctx *ctx);
bool		handle_sign(const char *s, t_valid_ctx *ctx);
bool		handle_sign(const char *s, t_valid_ctx *ctx);
bool		handle_digit(const char *s, t_valid_ctx *ctx);
void		handle_spaces_in_middle(const char *s, t_valid_ctx *ctx);
int			error_exit(t_stacks *stx);
int			program_exit(t_stacks *stx, char ***arrs);
void		free_arrs_arr(char ***arrs, int *arr);

#endif
