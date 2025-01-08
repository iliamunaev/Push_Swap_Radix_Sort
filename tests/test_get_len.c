/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:16:52 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/08 18:23:52 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "../src/utils.c"

void test_get_len()
{
	char *av1[] = {"./prog", "1 2"};
	assert(get_len(2, av1) == 2);

	char *av2[] = {"./prog", "   "};
	assert(get_len(2, av2) == 0);

	char *av3[] = {"./prog", "  -1   2  ", "54 42"};
	assert(get_len(3, av3) == 4);

	char *av4[] = {"./prog", ""};
	assert(get_len(2, av4) == 0);

	char *av5[] = {"./prog", "  -234 ", " 777 two	"};
	assert(get_len(3, av5) == 3);

	char *av6[] = {"./prog", "	", "	two	 1 "};
	assert(get_len(3, av6) == 2);

	printf("All tests for get_len passed.\n");
}

int main()
{
	test_get_len();
	return 0;
}
