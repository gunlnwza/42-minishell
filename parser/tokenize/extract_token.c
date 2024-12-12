/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:22 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:08:41 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "token.h"

static t_token_type	get_token_type(char *line)
{
	if (ft_strncmp(line, ">>", 2) == 0)
		return (APPEND);
	if (ft_strncmp(line, ">", 1) == 0)
		return (OUTFILE);
	if (ft_strncmp(line, "<<", 2) == 0)
		return (HEREDOC);
	if (ft_strncmp(line, "<", 1) == 0)
		return (INFILE);
	if (ft_strncmp(line, "|", 1) == 0)
		return (PIPE);
	return (WORD);
}

static char	*get_word(char *line)
{
	size_t	length;
	int		state;

	length = 0;
	state = OUTSIDE;
	while (line[length])
	{
		if (state == OUTSIDE)
		{
			if (line[length] == '\'')
				state = INSIDE_SINGLE_QUOTE;
			else if (line[length] == '\"')
				state = INSIDE_DOUBLE_QUOTE;
			else if (ft_isinset(line[length], " \t<>|", 5))
				break ;
		}
		else if (state == INSIDE_SINGLE_QUOTE && line[length] == '\'')
			state = OUTSIDE;
		else if (state == INSIDE_DOUBLE_QUOTE && line[length] == '\"')
			state = OUTSIDE;
		length++;
	}
	return (ft_substr(line, 0, length));
}

static char	*get_token_str(char *line, t_token_type type)
{
	if (type == APPEND)
		return (ft_strdup(">>"));
	if (type == OUTFILE)
		return (ft_strdup(">"));
	if (type == HEREDOC)
		return (ft_strdup("<<"));
	if (type == INFILE)
		return (ft_strdup("<"));
	if (type == PIPE)
		return (ft_strdup("|"));
	return (get_word(line));
}

t_token	*extract_token(char *line)
{
	t_token_type	type;
	char			*str;
	t_token			*token;

	type = get_token_type(line);
	str = get_token_str(line, type);
	if (str == NULL)
		return (NULL);
	token = create_token(str, type);
	free(str);
	if (token == NULL)
		return (NULL);
	return (token);
}
