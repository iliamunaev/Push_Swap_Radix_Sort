/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:35:45 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/12 11:48:27 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Safely converts a string to a long integer.
 *
 * This function handles whitespace, signs, and checks for integer overflow
 * or underflow. If an overflow or underflow occurs, it returns VALUE_ERROR.
 *
 * @param s The string to convert.
 * @return long int The converted number, or VALUE_ERROR on failure.
 */
static long int	ft_atoi_safe(char *s)
{
	int			sign;
	int			i;
	long		num;

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
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (VALUE_ERROR);
		i++;
	}
	return ((long int)(num * sign));
}

/**
 * @brief Fills an integer array from a split array of strings.
 *
 * Converts the strings in the split array into integers and stores them in
 * the provided array. If an error occurs (e.g., invalid input or overflow),
 * it frees allocated memory and returns 0.
 *
 * @param arrs The split array of strings.
 * @param arr The integer array to fill.
 * @return int 1 on success, 0 on failure.
 */
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
			{
				free_arrs_arr(arrs, arr);
				return (0);
			}
			arr[idx] = (int)num;
			idx++;
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Converts a split array of strings into an array of integers.
 *
 * Allocates memory for an integer array and fills it with numbers
 * converted from the provided split array of strings.
 *
 * @param size The size of the resulting integer array.
 * @param arrs The split array of strings.
 * @return int* Pointer to the integer array, or NULL on failure.
 */
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

/**
 * @brief Calculates the total number of elements in a split array.
 *
 * Iterates through the split array and counts the total number of strings.
 *
 * @param arrs The split array of strings.
 * @return int The total number of elements in the split array.
 */
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

/**
 * @brief Splits input arguments into a 3D array of strings.
 *
 * Each input string is split using spaces as delimiters. The result is a
 * 3D array where each sub-array represents the split strings of one input.
 *
 * @param ac The number of input arguments.
 * @param av The array of input argument strings.
 * @return char*** A 3D array of split strings, or NULL on failure.
 */
char	***split_arrs(int ac, char **av)
{
	char	***arrs;
	int		i;
	int		j;

	arrs = malloc(ac * sizeof(char **));
	if (!arrs)
		return (NULL);
	i = 1;
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
