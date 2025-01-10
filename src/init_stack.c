/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:49:30 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 11:23:35 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>
t_node	*create_node(int x)
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
	size--;
	while (size >= 0)
	{
		stx->a->head = insert_num(stx->a->head, arr[size]);
		if (!stx->a->head)
			error_exit(stx);
		stx->a->size++;
		size--;
	}
	return (stx);
}

static long int 	ft_atoi_safe(char *s)
{
	int			sign;
	int i;
	long long	num;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (ft_issign(s[i]))
	{
		if(s[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		num = num * 10 + (s[i] - '0');
		if(num > INT_MAX || num < INT_MIN)
			return(VALUE_ERROR);
		i++;
	}
	return ((long int)(num * sign));
}

int	fill_int_arr(char ***arrs, int *arr)
{
	int	i;
	int	j;
	int	idx;
	long	num;

	i = 0;
	idx = 0;
	while (arrs[i])
	{
		j = 0;
		while (arrs[i][j])
		{
			num = ft_atoi_safe(arrs[i][j]);
			if(num == VALUE_ERROR)
				return(0);
			arr[idx] = (int)num;
			idx++;
			j++;
		}
		i++;
	}
	return(1);
}

int	*get_int_arr(int size, char ***arrs)
{
	int	*arr;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	if(!fill_int_arr(arrs, arr))
		return (NULL);
	free_split_arrs(arrs);
	return (arr);
}

int	get_len_arr(char ***arrs)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (arrs[i])
	{
		j = 0;
		while (arrs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

char	***split_arrs(int ac, char **av)
{
	char	***arrs;
	int	i;
	int	j;

	arrs = malloc((ac + 1) * sizeof(char **));
	if (!arrs)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ac)
	{
		arrs[j] = ft_split(av[i], ' ');
		if (!arrs[j])
		{
			free_split_arrs(arrs);
			return (NULL);
		}
		i++;
		j++;
	}
	arrs[j] = NULL;
	return (arrs);
}

t_stacks	*creat_stacks(void)
{
	t_stacks	*stx;
	stx = malloc(sizeof(t_stacks));
		if (!stx)
			return (NULL);
	stx->a = NULL;
	stx->b = NULL;
	stx->a = malloc(sizeof(t_stack));
	if (!stx->a)
		error_exit(stx);
	stx->a->head = NULL;
	stx->a->size = 0;
	stx->b = malloc(sizeof(t_stack));
	if (!stx->b)
		error_exit(stx);
	stx->b->head = NULL;
	stx->b->size = 0;
	return(stx);
}

t_stacks	*init_stack(int ac, char **av)
{
	int	*arr;
	int	size;
	t_stacks	*stx;
	char 	***arrs;

	stx = creat_stacks();
	arrs = split_arrs(ac, av);
	if (!arrs)
		error_exit(stx);
	size = get_len_arr(arrs);
	if(size == 0 || size == 1)
		program_exit(stx, arrs);
	arr = get_int_arr(size, arrs);
	if (!arr)
		error_exit(stx);
	if(is_duplicate(arr, size))
		error_exit(stx);
	stx = fill_up_stack(stx, arr, size);
	free(arr);
	return (stx);
}
