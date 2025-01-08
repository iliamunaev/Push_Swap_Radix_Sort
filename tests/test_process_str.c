/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_process_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:26:10 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/08 17:29:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "../src/utils.c"

void test_process_str()
{
	assert(process_str("hello world") == 2);
	assert(process_str("   ") == 0);
	assert(process_str("   a   b  ") == 2);
	assert(process_str("") == 0);
	assert(process_str(NULL) == 0);
	assert(process_str("word") == 1);
	assert(process_str("  multiple   spaces  ") == 2);
	assert(process_str("  multiple   spaces  4   words") == 4);

	printf("All tests for process_str passed.\n");
}
int main()
{
	test_process_str();
	return 0;
}
