/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:41:39 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 20:22:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// TEST ------------------------
// Helper function to print all integers in stack_a
#include <stdio.h>
/*
static void print_test_stack(t_stacks *stx)
{
    if (!stx)
    {
        printf("Error: The stack structure is NULL.\n");
        return;
    }
    printf("\n");

    t_node *current_a = stx->a ? stx->a->head : NULL;
    t_node *current_b = stx->b ? stx->b->head : NULL;

    // Determine the maximum height of the two stacks
    int height_a = 0, height_b = 0;

    // Calculate height of stack_a
    if (current_a)
    {
        t_node *temp = current_a;
        do
        {
            height_a++;
            temp = temp->next;
        } while (temp != current_a);
    }

    // Calculate height of stack_b
    if (current_b)
    {
        t_node *temp = current_b;
        do
        {
            height_b++;
            temp = temp->next;
        } while (temp != current_b);
    }

    // Determine the maximum height of the two stacks
    int max_height = (height_a > height_b) ? height_a : height_b;

    for (int i = 0; i < max_height; i++)
    {
        // Print stack_a's current value and index
        if (i < height_a && current_a)
        {
            printf("%-5d %-5d", current_a->value, current_a->index); // Align output for stack_a
            current_a = current_a->next;
        }
        else
        {
            printf("          "); // Print spaces if stack_a has fewer elements
        }

        // Tab space between stack_a and stack_b columns
        printf("\t");

        // Print stack_b's current value and index
        if (i < height_b && current_b)
        {
            printf("%-5d %-5d", current_b->value, current_b->index); // Align output for stack_b
            current_b = current_b->next;
        }
        else
        {
            printf("          "); // Print spaces if stack_b has fewer elements
        }

        printf("\n");
    }

    // Print the bottom separator and labels
    printf("----- -----\t----- -----\n");
    printf("  a    idx\t  b    idx\n");
    printf("--------------------------\n\n");
}
*/
// ***********************************************************/
// END TEST ******************************************************/

int	main(int ac, char **av)
{
	t_stacks	*stx;

	// validation()

	// Initialize stacks
	stx = init_stack(ac - 1, av + 1); // Skip the program name
	if (!stx)
		return (1);

/*
	printf("Initial Stacks:\n");
	print_test_stack(stx);
*/

	if(!assign_index(stx))
		return 1;

	//printf("Indexed Stacks:\n");
	//print_test_stack(stx);
/*
	sa(stx);
	print_test_stack(stx);

	pb(stx);
	print_test_stack(stx);

	pb(stx);
	print_test_stack(stx);

	sb(stx);
	print_test_stack(stx);

	rrb(stx);
	print_test_stack(stx);

	pa(stx);
	print_test_stack(stx);

	pa(stx);
	print_test_stack(stx);

	rra(stx);
	print_test_stack(stx);
*/


	// Run algorithm
	if(!is_sorted(stx))
	{
		//printf("Not sorted...\n");
		sort(stx);
	}
	//else
	//	printf("yes\n");


	//print_test_stack(stx);


	free_stx(stx);
	return (0);
}
