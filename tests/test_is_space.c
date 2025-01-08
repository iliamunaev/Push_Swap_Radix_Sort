/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:18:08 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/08 18:18:09 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "../src/utils.c"

void test_is_space()
{
    assert(is_space(' ') == 1);  // Space character
    assert(is_space('\t') == 1);  // Tab character
    assert(is_space('\n') == 0);  // Newline is not space
    assert(is_space('a') == 0);  // Non-space character
    assert(is_space('1') == 0);  // Non-space digit
    assert(is_space('\0') == 0);  // Null character
    printf("All tests for is_space passed.\n");
}
int main()
{
	test_is_space();
	return 0;
}
