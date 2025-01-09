/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_safe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:17:08 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 13:17:16 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void test_ft_atoi_safe()
{
	// Test valid inputs
	assert(ft_atoi_safe("12345") == 12345);
	assert(ft_atoi_safe("-12345") == -12345);
	assert(ft_atoi_safe("+12345") == 12345);
	assert(ft_atoi_safe("	12345") == 12345);
	assert(ft_atoi_safe("	-12345") == -12345);
	assert(ft_atoi_safe("\t\n12345") == 12345);

	// Test inputs with overflow/underflow
	assert(ft_atoi_safe("2147483648") == VALUE_ERROR);  // Greater than INT_MAX
	assert(ft_atoi_safe("-2147483649") == VALUE_ERROR); // Less than INT_MIN

	// Test inputs with invalid characters
	assert(ft_atoi_safe("123abc") == 123); // Stops parsing at invalid character
	assert(ft_atoi_safe("-123abc") == -123);
	assert(ft_atoi_safe("+123abc") == 123);

	// Test edge cases
	assert(ft_atoi_safe("0") == 0);
	assert(ft_atoi_safe("-0") == 0);

	printf("ft_atoi_safe: All tests passed successfully!\n");
}

int main()
{
	test_ft_atoi_safe();
	return 0;
}
