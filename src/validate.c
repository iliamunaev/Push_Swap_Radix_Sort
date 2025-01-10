/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:40 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 13:53:46 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static bool	skip_initial_spaces(const char *s, t_valid_ctx *ctx)
{
	while (ft_isspace(s[ctx->i]))
		ctx->i++;
	if (!s[ctx->i])
		return (false);
	return (true);
}

static bool	handle_sign(const char *s, t_valid_ctx *ctx)
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

static bool	handle_digit(const char *s, t_valid_ctx *ctx)
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

static void	handle_spaces_in_middle(const char *s, t_valid_ctx *ctx)
{
	while (ft_isspace(s[ctx->i]))
		ctx->i++;
	ctx->in_number = false;
	ctx->leading_zero = false;
}

int	is_valid(const char *s)
{
	t_valid_ctx	ctx = {0};

	if (!skip_initial_spaces(s, &ctx))
		return (0);
	while (s[ctx.i])
	{
		if (ft_issign(s[ctx.i]))
		{
			if (!handle_sign(s, &ctx))
				return (0);
			continue ;
		}
		if (ft_isdigit(s[ctx.i]))
		{
			if (!handle_digit(s, &ctx))
				return (0);
			continue ;
		}
		if (ft_isspace(s[ctx.i]))
		{
			handle_spaces_in_middle(s, &ctx);
			continue ;
		}
		return (0);
	}
	if (ctx.found_digit == 0)
		return (0);
	return (1);
}

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
