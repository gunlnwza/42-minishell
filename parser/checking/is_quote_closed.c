/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:20:01 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/26 11:30:25 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize/token.h"

static void	update_state(int *state, char *line)
{
	if (*state == OUTSIDE)
	{
		if (*line == '\'')
			*state = INSIDE_SINGLE_QUOTE;
		else if (*line == '\"')
			*state = INSIDE_DOUBLE_QUOTE;
	}
	else if (*state == INSIDE_SINGLE_QUOTE)
	{
		if (*line == '\'')
			*state = OUTSIDE;
	}
	else if (*state == INSIDE_DOUBLE_QUOTE)
	{
		if (*line == '\"')
			*state = OUTSIDE;
	}
}

int	is_quote_closed(char *line)
{
	int	state;

	state = OUTSIDE;
	while (*line)
	{
		update_state(&state, line);
		line++;
	}
	return (state == OUTSIDE);
}
