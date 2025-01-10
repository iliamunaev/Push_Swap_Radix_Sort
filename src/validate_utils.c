/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:58:21 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 13:58:57 by imunaev-         ###   ########.fr       */
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

bool	skip_initial_spaces(const char *s, t_valid_ctx *ctx)
{
	while (ft_isspace(s[ctx->i]))
		ctx->i++;
	if (!s[ctx->i])
		return (false);
	return (true);
}

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

void	handle_spaces_in_middle(const char *s, t_valid_ctx *ctx)
{
	while (ft_isspace(s[ctx->i]))
		ctx->i++;
	ctx->in_number = false;
	ctx->leading_zero = false;
}
