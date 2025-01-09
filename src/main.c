/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:41:39 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/09 14:18:54 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// TEST ------------------------
// Helper function to print all integers in stack_a
#include <stdio.h>

static void print_test_stack(t_stacks *stx)
{
    if (!stx)
    {
        printf("Error: The stack structure is NULL.\n");
        return;
    }

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
        // Print stack_a's current value
        if (i < height_a && current_a)
        {
            printf("%-5d", current_a->value); // Align output for stack_a
            current_a = current_a->next;
        }
        else
        {
            printf("     "); // Print spaces if stack_a has fewer elements
        }

        // Tab space between the two stacks
        printf("\t");

        // Print stack_b's current value
        if (i < height_b && current_b)
        {
            printf("%-5d", current_b->value); // Align output for stack_b
            current_b = current_b->next;
        }
        else
        {
            printf("     "); // Print spaces if stack_b has fewer elements
        }

        printf("\n");
    }

    // Print the bottom separator and labels
    printf("-----\t-----\n");
    printf("  a  \t  b  \n");
    printf("\n");
}

// ***********************************************************/
// TEST ******************************************************/



int	main(int ac, char **av)
{
	t_stacks	*stx;

	// validation()

	// Initialize stacks
	stx = init_stack(ac - 1, av + 1); // Skip the program name
	if (!stx)
		return (1);



	printf("Initial Stacks:\n");
	print_test_stack(stx);
	printf("--------------------------\n");

	// Run Push_Swap algorithm
	//push_swap(stx);
/*
	printf("After Stacks:\n");
	print_test_stack(stx->stack_a, stx->stack_b);
	printf("--------------------------\n");
*/
	// Free memory and exit
	free_stx(stx);
	return (0);
}
