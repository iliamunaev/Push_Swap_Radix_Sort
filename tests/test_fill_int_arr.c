/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fill_int_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:27:40 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 13:27:45 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define VALUE_ERROR LONG_MAX

static int ft_issign(char c)
{
	return (c == '-' || c == '+');
}

static int ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\f' || c == '\r' || c == '\t' || c == '\v');
}

static long int ft_atoi_safe(char *s)
{
	int sign = 1;
	int i = 0;
	long long num = 0;

	while (ft_isspace(s[i]))
		i++;

	if (ft_issign(s[i]))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		if (num > INT_MAX || num < INT_MIN)
			return (VALUE_ERROR);
		i++;
	}
	return ((long int)(num * sign));
}

void	free_split_arrs(char ***arrs)
{
	int	i;
	int	j;

	if (!arrs)
		return ;
	i = 0;
	while (arrs[i] != NULL)
	{
		j = 0;
		while (arrs[i][j] != NULL)
		{
			free(arrs[i][j]);
			j++;
		}
		free(arrs[i]);
		i++;
	}
	free(arrs);
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

	arr = malloc((size + 1)* sizeof(int));
	if (!arr)
	{
		free_split_arrs(arrs);
		return (NULL);
	}
	if(!fill_int_arr(arrs, arr))
		return (NULL);
	free_split_arrs(arrs);
	return (arr);
}
void test_fill_int_arr()
{
	// Test 1: Basic valid input
	char *arr1_1[] = {"1", "2", "3", NULL};
	char *arr1_2[] = {"4", "5", "6", NULL};
	char **arr1[] = {arr1_1, arr1_2, NULL};
	int result1[6];
	assert(fill_int_arr(arr1, result1) == 1);
	assert(result1[0] == 1);
	assert(result1[1] == 2);
	assert(result1[2] == 3);
	assert(result1[3] == 4);
	assert(result1[4] == 5);
	assert(result1[5] == 6);

	// Test 2: Single sub-array
	char *arr2_1[] = {"42", "84", NULL};
	char **arr2[] = {arr2_1, NULL};
	int result2[2];
	assert(fill_int_arr(arr2, result2) == 1);
	assert(result2[0] == 42);
	assert(result2[1] == 84);

	// Test 3: Multiple sub-arrays with varying lengths
	char *arr3_1[] = {"10", "20", NULL};
	char *arr3_2[] = {"30", NULL};
	char *arr3_3[] = {"40", "50", "60", NULL};
	char **arr3[] = {arr3_1, arr3_2, arr3_3, NULL};
	int result3[6];
	assert(fill_int_arr(arr3, result3) == 1);
	assert(result3[0] == 10);
	assert(result3[1] == 20);
	assert(result3[2] == 30);
	assert(result3[3] == 40);
	assert(result3[4] == 50);
	assert(result3[5] == 60);

	// Print results to verify correctness
	printf("Test 1: ");
	for (int i = 0; i < 6; i++) printf("%d ", result1[i]);
	printf("\n");

	printf("Test 2: ");
	for (int i = 0; i < 2; i++) printf("%d ", result2[i]);
	printf("\n");

	printf("Test 3: ");
	for (int i = 0; i < 6; i++) printf("%d ", result3[i]);
	printf("\n");

	printf("All tests passed successfully!\n");
}


int main()
{
	test_fill_int_arr();
	return 0;
}
