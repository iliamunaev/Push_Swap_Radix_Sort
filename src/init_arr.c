/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:35:45 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:42:32 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long int	ft_atoi_safe(char *s)
{
	int			sign;
	int			i;
	long long	num;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (ft_issign(s[i]))
	{
		if (s[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		num = num * 10 + (s[i] - '0');
		if (num > INT_MAX || num < INT_MIN)
			return (VALUE_ERROR);
		i++;
	}
	return ((long int)(num * sign));
}

static int	fill_int_arr(char ***arrs, int *arr)
{
	int		i;
	int		j;
	int		idx;
	long	num;

	i = 0;
	idx = 0;
	while (arrs[i])
	{
		j = 0;
		while (arrs[i][j])
		{
			num = ft_atoi_safe(arrs[i][j]);
			if (num == VALUE_ERROR)
				return (0);
			arr[idx] = (int)num;
			idx++;
			j++;
		}
		i++;
	}
	return (1);
}

int	*get_int_arr(int size, char ***arrs)
{
	int	*arr;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	if (!fill_int_arr(arrs, arr))
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
	int		i;
	int		j;

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
