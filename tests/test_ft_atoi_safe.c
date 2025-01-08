/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_safe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:52:44 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/08 20:20:47 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../src/init_stacks.c"
#include "../src/utils.c"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int main()
{
	printf("\n*****Valid cases*****\n\n");
    printf("Valid. -12345: [%lld]\n", ft_atoi_safe("  -12345"));
    printf("Valid. +12345: [%lld]\n", ft_atoi_safe("  +12345"));
    printf("Valid. Following spaces '12345  ': [%lld]\n", ft_atoi_safe("12345  "));
	printf("Valid. Leading spaces '    42': [%lld]\n", ft_atoi_safe("    42"));
    printf("Valid. Leading tabs '		42': [%lld]\n", ft_atoi_safe("		42"));

	printf("\n*****Invalid cases*****\n\n");
    printf("Invalid. Overflow '2147483648': %lld\n", ft_atoi_safe("2147483648"));
    printf("Invalid. Underflow '-2147483649': %lld\n", ft_atoi_safe("-2147483649"));
    printf("Invalid. Following char '123abc': %lld\n", ft_atoi_safe("123abc"));
	printf("Invalid. Empty string: %lld\n", ft_atoi_safe(""));
    printf("Invalid. Leading '-+42': %lld\n", ft_atoi_safe("  -+42"));
    printf("Invalid. Sing befor and after num '-42-': %lld\n", ft_atoi_safe("-42-"));

    return (0);
}
