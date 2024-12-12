/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:07:38 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 15:47:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../tokenize/token.h"
#include "command.h"

int	get_argv_and_redirs(t_command *command, t_list *tokens);

static void	get_argc(t_command *command, t_list *tokens)
{
	t_token	*token;

	while (tokens)
	{
		token = tokens->content;
		if (token->type == PIPE)
			break ;
		else if (token->type == WORD)
			command->argc++;
		else if (is_redir(token->type))
			tokens = tokens->next;
		tokens = tokens->next;
	}
}

static t_command	*create_command_from_tokens(t_list *tokens)
{
	t_command	*command;

	command = malloc_command();
	if (command == NULL)
		return (NULL);
	get_argc(command, tokens);
	if (get_argv_and_redirs(command, tokens) != SUCCESS)
	{
		free(command);
		return (NULL);
	}
	return (command);
}

// move to after-pipe token, or stop after the last token
static void	move_to_token_after_pipe(t_list **tokens)
{
	t_token	*token;

	while (*tokens)
	{
		token = (*tokens)->content;
		if (token->type == PIPE)
		{
			*tokens = (*tokens)->next;
			break ;
		}
		*tokens = (*tokens)->next;
	}
}

t_command_list	*create_command_list(t_list *tokens)
{
	t_command_list	*command_list;
	t_command		*command;

	command_list = NULL;
	while (tokens)
	{
		command = create_command_from_tokens(tokens);
		if (command == NULL)
		{
			ft_lstclear(&command_list, free_command);
			return (NULL);
		}
		if (!ft_lstnew_add_back(&command_list, command))
		{
			free(command);
			ft_lstclear(&command_list, free_command);
			return (NULL);
		}
		move_to_token_after_pipe(&tokens);
	}
	return (command_list);
}
