/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv_and_redirs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:42:43 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/15 14:59:12 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../tokenize/token.h"
#include "command.h"

static int	handle_word(t_command *command, t_list **tokens, int *i)
{
	t_token	*token;

	token = (*tokens)->content;
	command->argv[*i] = ft_strdup(token->str);
	if (command->argv[*i] == NULL)
		return (ERROR);
	(*i)++;
	return (SUCCESS);
}

static int	handle_redir(t_command *command, t_list **tokens)
{
	t_token	*token;
	t_token	*new_token;

	token = (*tokens)->content;
	new_token = copy_token(token);
	if (new_token == NULL || !ft_lstnew_add_back(&command->redirs, new_token))
		return (ERROR);
	*tokens = (*tokens)->next;
	token = (*tokens)->content;
	new_token = copy_token(token);
	if (new_token == NULL || !ft_lstnew_add_back(&command->redirs, new_token))
		return (ERROR);
	return (SUCCESS);
}

static int	handle_word_or_redir(t_command *command, t_list **tokens, int *i)
{
	t_token	*token;
	int		ret;

	token = (*tokens)->content;
	if (token->type == WORD)
		ret = handle_word(command, tokens, i);
	else
		ret = handle_redir(command, tokens);
	return (ret);
}

int	get_argv_and_redirs(t_command *command, t_list *tokens)
{
	t_token	*token;
	int		i;

	command->argv = malloc((command->argc + 1) * sizeof(char *));
	if (command->argv == NULL)
		return (ERROR);
	i = 0;
	while (tokens)
	{
		token = tokens->content;
		if (token->type == PIPE)
			break ;
		if (handle_word_or_redir(command, &tokens, &i) != SUCCESS)
		{
			ft_free_str_arr(command->argv, i);
			ft_lstclear(&command->redirs, free_token);
			free(command);
			return (ERROR);
		}
		tokens = tokens->next;
	}
	command->argv[i] = NULL;
	return (SUCCESS);
}
