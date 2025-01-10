/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:40 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:14:49 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	process_current_char(const char *s, t_valid_ctx *ctx)
{
	if (ft_issign(s[ctx->i]))
	{
		if (!handle_sign(s, ctx))
			return (0);
		return (2);
	}
	if (ft_isdigit(s[ctx->i]))
	{
		if (!handle_digit(s, ctx))
			return (0);
		return (2);
	}
	if (ft_isspace(s[ctx->i]))
	{
		handle_spaces_in_middle(s, ctx);
		return (2);
	}
	return (1);
}

int	is_valid(const char *s)
{
	t_valid_ctx	ctx;
	int			result;

	ft_bzero(&ctx, sizeof(t_valid_ctx));
	if (!skip_initial_spaces(s, &ctx))
		return (0);
	while (s[ctx.i])
	{
		result = process_current_char(s, &ctx);
		if (result == 0)
			return (0);
		if (result == 1)
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
