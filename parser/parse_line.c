/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/07 15:58:37 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../libft/libft.h"
#include "parse_line.h"

#define KEEP_PARSING TRUE
#define STOP FALSE

t_token_list	*tokenize_line(char *line);
void			expand_tokens(t_list **tokens, t_shell_data *data);

int				is_quote_closed(char *line);
int				is_grammar_correct(t_list *tokens);

t_command_list	*create_command_list(t_list *tokens);

static int	process_line_into_tokens(char *line, t_list	**tokens, \
	t_shell_data *data)
{
	*tokens = tokenize_line(line);
	if (*tokens == NULL)
		return (ENOMEM);
	expand_tokens(tokens, data);
	if (*tokens == NULL)
		return (ENOMEM);
	return (KEEP_PARSING);
}

// if syntax error: free tokens, and tell the parser to stop
static int	check_syntax(t_token_list **tokens)
{
	if (!is_grammar_correct(*tokens))
	{
		ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
		ft_lstclear(tokens, free_token);
		return (EINVAL);
	}
	return (KEEP_PARSING);
}

// process line, check syntax (and set error_code accordingly)
// if syntax correct: set data->command_list = <parsed_commands>
// else: data->command_list = NULL
//
// assume result is SUCCESS unless find error afterward
int	parse_line(char *line, t_shell_data *data,
	t_command_list **commands)
{
	t_token_list	*tokens;
	int				ret;

	if (ft_strlen(line) == 0)
		return (SUCCESS);
	else if (!is_quote_closed(line))
	{
		ft_putstr_fd("minishell: quote error\n", STDERR_FILENO);
		return (EINVAL);
	}
	ret = process_line_into_tokens(line, &tokens, data);
	if (ret != KEEP_PARSING)
		return (ret);
	ret = check_syntax(&tokens);
	if (ret != KEEP_PARSING)
		return (ret);
	*commands = create_command_list(tokens);
	ft_lstclear(&tokens, free_token);
	if (commands == NULL)
		return (ENOMEM);
	return (SUCCESS);
}
