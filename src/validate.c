/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:40 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/12 11:22:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Processes the current character in the string during validation.
 *
 * Handles the character based on whether it is a sign, digit, or whitespace,
 * and updates the validation context accordingly. Returns a result indicating
 * the success or failure of the processing.
 *
 * @param s The string being validated.
 * @param ctx Pointer to the validation context.
 * @return int false on failure, true if character is invalid
 */
static bool	process_current_char(const char *s, t_valid_ctx *ctx)
{
	if (ft_issign(s[ctx->i]))
	{
		if (!handle_sign(s, ctx))
			return (false);
		return (true);
	}
	if (ft_isdigit(s[ctx->i]))
	{
		if (!handle_digit(s, ctx))
			return (false);
		return (true);
	}
	if (ft_isspace(s[ctx->i]))
	{
		handle_spaces_in_middle(s, ctx);
		return (true);
	}
	return (false);
}

/**
 * @brief Validates a single string as a potential input for the program.
 *
 * Ensures the string contains valid numbers, signs, and whitespace characters
 * in a proper format. Returns true if the string is valid, false otherwise.
 *
 * @param s The string to validate.
 * @return int true if valid, false if invalid.
 */
static bool	is_valid(const char *s)
{
	t_valid_ctx	ctx;
	int			result;

	ft_bzero(&ctx, sizeof(t_valid_ctx));
	if (!skip_initial_spaces(s, &ctx))
		return (false);
	while (s[ctx.i])
	{
		result = process_current_char(s, &ctx);
		if (result == 0)
			return (false);
	}
	if (ctx.found_digit == false)
		return (false);
	return (true);
}

/**
 * @brief Validates the input arguments for the program.
 *
 * Iterates through all arguments, ensuring each is
 * a valid string representation
 * of numbers (using `is_valid`). Returns 1 if all arguments
 * are valid, 0 otherwise.
 *
 * @param ac The number of input arguments.
 * @param av The array of input argument strings.
 * @return int 1 if all input arguments are valid, 0 otherwise.
 */
int	validate_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		if (!is_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}
