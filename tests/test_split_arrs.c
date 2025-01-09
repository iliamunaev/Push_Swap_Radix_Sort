/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_arrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:44:45 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 12:44:47 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include"../src/init_stack.c"
#include"../src/utils.c"

void	test_split_arrs()
{
	// Test 1: Basic valid input
	char *input1[] = {"./program_name", "1 2 34567", "   4 -5", "	6  ", NULL};
	char ***result1 = split_arrs(4, input1);
	assert(result1 != NULL);

	// Check the split results for av[1]
	assert(strcmp(result1[0][0], "1") == 0);
	assert(strcmp(result1[0][1], "2") == 0);
	assert(strcmp(result1[0][2], "34567") == 0);
	assert(result1[0][3] == NULL);

	// Check the split results for av[2]
	assert(strcmp(result1[1][0], "4") == 0);
	assert(strcmp(result1[1][1], "-5") == 0);
	assert(result1[1][2] == NULL);

	// Check the split results for av[3]
	assert(strcmp(result1[2][0], "6") == 0);
	assert(result1[2][1] == NULL);

	// Check the final NULL marker for result1
	assert(result1[3] == NULL);

	free_split_arrs(result1);

	printf("All tests passed successfully!\n");
}

int main()
{
	test_split_arrs();
	return (0);
}
