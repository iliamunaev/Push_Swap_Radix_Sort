/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:44:08 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 13:44:08 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

typedef struct s_valid_ctx
{
	int		i;				// current index in the string
	bool	in_number;		// are we currently parsing a number?
	bool	leading_zero;	// did we see '0' as first digit of current number?
	int		found_digit;	// have we encountered at least one digit in the entire string?
} t_valid_ctx;

static int ft_issign(char c)
{
	return(c == '-' || c == '+');
}

static int ft_isspace(char c)
{
	return(c == ' ' || c == '\n' || c == '\f' || c == '\r' || c == '\t' || c == '\v');
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool skip_initial_spaces(const char *s, t_valid_ctx *ctx)
{
	while (ft_isspace(s[ctx->i]))
		ctx->i++;

	// If we reached the end, it's all spaces => invalid
	if (!s[ctx->i])
		return false;

	return true;
}

static bool handle_sign(const char *s, t_valid_ctx *ctx)
{
	// If we're already parsing a number and see a sign => invalid
	if (ctx->in_number)
		return false;

	// Next char also sign => invalid
	if (ft_issign(s[ctx->i + 1]))
		return false;

	// Sign followed by space => invalid
	if (ft_isspace(s[ctx->i + 1]) && s[ctx->i + 1] != '\0')
		return false;

	// Sign is last char => invalid
	if (!s[ctx->i + 1])
		return false;

	// Reset number parsing state
	ctx->in_number = false;
	ctx->leading_zero = false;

	// Move past the sign
	ctx->i++;
	return true;
}

static bool handle_digit(const char *s, t_valid_ctx *ctx)
{
	if (!ctx->in_number)
	{
		// Starting a new number
		ctx->in_number = true;
		ctx->found_digit = 1; // we have at least one digit overall

		if (s[ctx->i] == '0')
			ctx->leading_zero = true;
		else
			ctx->leading_zero = false;
	}
	else
	{
		// Already in a number
		if (ctx->leading_zero && s[ctx->i] != '0')
			return false; // leading zero "01", "0123", etc.
	}

	// consume this digit
	ctx->i++;
	return true;
}

static void handle_spaces_in_middle(const char *s, t_valid_ctx *ctx)
{
	// Skip all consecutive spaces
	while (ft_isspace(s[ctx->i]))
		ctx->i++;

	// Reset in_number state for the next potential number
	ctx->in_number = false;
	ctx->leading_zero = false;
}

int is_valid(const char *s)
{
	t_valid_ctx ctx = {0};
	// i=0, in_number=false, leading_zero=false, found_digit=0

	// 1) Skip leading spaces. If all spaces => invalid
	if (!skip_initial_spaces(s, &ctx))
		return 0;

	// 2) Main loop
	while (s[ctx.i])
	{
		// a) Sign?
		if (ft_issign(s[ctx.i]))
		{
			if (!handle_sign(s, &ctx))
				return 0;
			continue;
		}

		// b) Digit?
		if (ft_isdigit(s[ctx.i]))
		{
			if (!handle_digit(s, &ctx))
				return 0;
			continue;
		}

		// c) Space in the middle?
		if (ft_isspace(s[ctx.i]))
		{
			handle_spaces_in_middle(s, &ctx);
			continue;
		}

		// d) Any other character => invalid
		return 0;
	}

	// 3) Must have at least one digit overall
	if (ctx.found_digit == 0)
		return 0;

	return 1;
}

// A small helper for running each test
static void test_is_valid(const char *input, int expected)
{
	int got = is_valid((char*)input);
	printf("Test: \"%s\": [%d = %d] => %s\n",
		   input, got, expected, (got == expected) ? "PASS" : "FAIL");
}
int main(void)
{

	test_is_valid("42", 1);
	test_is_valid("+42", 1);
	test_is_valid("-42", 1);
	test_is_valid("0", 1);
	test_is_valid("+0", 1);
	test_is_valid("-0", 1);
	test_is_valid("-01", 0);
	test_is_valid("+01", 0);
	test_is_valid("01", 0);
	test_is_valid(" 42", 1);
	test_is_valid("42 ", 1);
	test_is_valid("5+1", 0);
	test_is_valid("--1", 0);
	test_is_valid("++1", 0);
	test_is_valid("+ 42", 0);
	test_is_valid("+", 0);
	test_is_valid("-", 0);
	test_is_valid("  ", 0);
	test_is_valid("0123", 0);
	test_is_valid("--", 0);
	test_is_valid("+5   6", 1);
	test_is_valid("7 66 -7", 1);
	test_is_valid("7 66 07", 0);
	test_is_valid("7 66 -07", 0);

	return (0);
}
