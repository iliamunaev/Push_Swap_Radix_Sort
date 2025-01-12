/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_issign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:06:24 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 13:06:25 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>

static int ft_issign(char c)
{
	return (c == '-' || c == '+');
}

void test_ft_issign()
{
	// Test for positive and negative signs
	assert(ft_issign('-') == 1);
	assert(ft_issign('+') == 1);

	// Test for non-sign characters
	assert(ft_issign('a') == 0);
	assert(ft_issign('1') == 0);
	assert(ft_issign(' ') == 0);
	assert(ft_issign('\0') == 0);

	printf("ft_issign: All tests passed successfully!\n");
}

int main()
{
	test_ft_issign();
	return 0;
}
