/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:58:21 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/11 00:05:02 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks for duplicate values in an integer array.
 *
 * Iterates through the array and compares each element to every other element
 * to identify duplicates.
 *
 * @param arr The array to check.
 * @param size The size of the array.
 * @return int 1 if duplicates are found, 0 otherwise.
 */
int	is_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Skips initial whitespace characters in a string.
 *
 * Advances the index in the validation context until a non-whitespace
 * character is encountered or the end of the string is reached.
 *
 * @param s The string to process.
 * @param ctx Pointer to the validation context.
 * @return bool `true` if a non-whitespace character is found, `false` otherwise.
 */
bool	skip_initial_spaces(const char *s, t_valid_ctx *ctx)
{
	while (ft_isspace(s[ctx->i]))
		ctx->i++;
	if (!s[ctx->i])
		return (false);
	return (true);
}

/**
 * @brief Handles a sign ('-' or '+') in the string during validation.
 *
 * Ensures that the sign is in a valid position and updates the validation
 * context accordingly.
 *
 * @param s The string being validated.
 * @param ctx Pointer to the validation context.
 * @return bool `true` if the sign is valid, `false` otherwise.
 */
bool	handle_sign(const char *s, t_valid_ctx *ctx)
{
	if (ctx->in_number)
		return (false);
	if (ft_issign(s[ctx->i + 1]))
		return (false);
	if (ft_isspace(s[ctx->i + 1]) && s[ctx->i + 1] != '\0')
		return (false);
	if (!s[ctx->i + 1])
		return (false);
	ctx->in_number = false;
	ctx->leading_zero = false;
	ctx->i++;
	return (true);
}

/**
 * @brief Handles a digit in the string during validation.
 *
 * Validates the digit's position, ensures there are no invalid leading zeros,
 * and updates the validation context accordingly.
 *
 * @param s The string being validated.
 * @param ctx Pointer to the validation context.
 * @return bool `true` if the digit is valid, `false` otherwise.
 */
bool	handle_digit(const char *s, t_valid_ctx *ctx)
{
	if (!ctx->in_number)
	{
		ctx->in_number = true;
		ctx->found_digit = 1;
		if (s[ctx->i] == '0')
			ctx->leading_zero = true;
		else
			ctx->leading_zero = false;
	}
	else
	{
		if (ctx->leading_zero && s[ctx->i] != '0')
			return (false);
	}
	ctx->i++;
	return (true);
}

/**
 * @brief Handles spaces found in the middle of a string during validation.
 *
 * Advances the index in the validation context past the spaces and resets
 * the validation context flags related to numbers.
 *
 * @param s The string being validated.
 * @param ctx Pointer to the validation context.
 */
void	handle_spaces_in_middle(const char *s, t_valid_ctx *ctx)
{
	while (ft_isspace(s[ctx->i]))
		ctx->i++;
	ctx->in_number = false;
	ctx->leading_zero = false;
}
