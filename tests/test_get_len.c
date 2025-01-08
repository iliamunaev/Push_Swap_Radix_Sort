/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:16:52 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/08 18:16:53 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "../src/utils.c"

void test_get_len()
{
	char *av1[] = {"./prog", "hello world"};
	assert(get_len(2, av1) == 2);

	char *av2[] = {"./prog", "   "};
	assert(get_len(2, av2) == 0);  // No words, 0 characters

	char *av3[] = {"./prog", "  a   b  ", "test case"};
	assert(get_len(3, av3) == 4);  // "a", "b", "test", "case"

	char *av4[] = {"./prog", ""};
	assert(get_len(2, av4) == 0);  // Empty argument, 0 characters

	char *av5[] = {"./prog", "  one ", " two three "};
	assert(get_len(3, av5) == 3);  // "one", "two", "three"

	printf("All tests for get_len passed.\n");
}

int main()
{
	test_get_len();
	return 0;
}
