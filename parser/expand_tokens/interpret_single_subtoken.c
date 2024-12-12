/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_single_subtoken.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:05:13 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../setup/shell_data.h"
#include "../tokenize/token.h"

int	expand_variable(t_list *cur_node, t_shell_data *data);

static void	delete_cur_node(t_list **subtokens, t_list *cur_node)
{
	if (cur_node->prev == NULL)
		*subtokens = cur_node->next;
	ft_lstdelone(cur_node, free_token);
}

static int	handle_outside(t_list **subtokens, t_list *cur_node,
	t_shell_data *data, int *state)
{
	t_token	*subtoken;

	subtoken = cur_node->content;
	if (subtoken->type == SINGLE_QUOTE)
	{
		delete_cur_node(subtokens, cur_node);
		*state = INSIDE_SINGLE_QUOTE;
	}
	else if (subtoken->type == DOUBLE_QUOTE)
	{
		delete_cur_node(subtokens, cur_node);
		*state = INSIDE_DOUBLE_QUOTE;
	}
	else if (subtoken->type == VARIABLE || subtoken->type == EXIT_STATUS)
		return (expand_variable(cur_node, data));
	return (SUCCESS);
}

static int	handle_inside_single_quote(t_list **subtokens, t_list *cur_node,
	t_shell_data *data, int *state)
{
	t_token	*subtoken;

	(void) data;
	subtoken = cur_node->content;
	if (subtoken->type == SINGLE_QUOTE)
	{
		delete_cur_node(subtokens, cur_node);
		*state = OUTSIDE;
	}
	return (SUCCESS);
}

static int	handle_inside_double_quote(t_list **subtokens, t_list *cur_node,
	t_shell_data *data, int *state)
{
	t_token	*subtoken;

	subtoken = cur_node->content;
	if (subtoken->type == DOUBLE_QUOTE)
	{
		delete_cur_node(subtokens, cur_node);
		*state = OUTSIDE;
	}
	else if (subtoken->type == VARIABLE || subtoken->type == EXIT_STATUS)
		return (expand_variable(cur_node, data));
	return (SUCCESS);
}

int	interpret_single_subtoken(t_list **subtokens, t_list *cur_node,
	t_shell_data *data, int *state)
{
	int	ret;

	ret = SUCCESS;
	if (*state == OUTSIDE)
		ret = handle_outside(subtokens, cur_node, data, state);
	else if (*state == INSIDE_SINGLE_QUOTE)
		ret = handle_inside_single_quote(subtokens, cur_node, data, state);
	else if (*state == INSIDE_DOUBLE_QUOTE)
		ret = handle_inside_double_quote(subtokens, cur_node, data, state);
	return (ret);
}
