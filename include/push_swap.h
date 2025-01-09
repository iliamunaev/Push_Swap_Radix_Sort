/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:40:14 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 18:34:02 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

#include <stdbool.h>    // for bool
#include <stdlib.h>     // for malloc, free
#include <limits.h>

#define VALUE_ERROR LONG_MAX

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
    t_node *head;
    int size;
} t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_find_number
{
    int value;
    bool found;
} t_find_number;

t_stacks	*init_stack(int ac, char **av);
char	***split_arrs(int ac, char **av);
int	get_len_arr(char ***arrs);
int	*get_int_arr(int size, char ***arrs);
t_stacks	*fill_up_stack(t_stacks *stx, int *arr, int size);
void	free_circular_list(t_node *head);
void	free_stx(t_stacks *stx);
t_node *insert_num(t_node *head, int value);
t_node	*create_node(int x);
void	free_split_arrs(char ***arrs);
int	assign_index(t_stacks *stx);

#endif
