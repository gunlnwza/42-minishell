/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:39:37 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:08:41 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "token.h"

// create malloc'd token
// - have malloc'd duplicate of str for token->str
// - have integer for token->type
// return NULL if malloc error
t_token	*create_token(char *str, int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = type;
	token->str = ft_strdup(str);
	if (token->str == NULL)
	{
		free(token);
		return (NULL);
	}
	return (token);
}

void	*copy_token(void *token)
{
	t_token	*token_;
	t_token	*new_token;

	token_ = token;
	new_token = create_token(token_->str, token_->type);
	if (new_token == NULL)
		return (NULL);
	return (new_token);
}

void	free_token(void *token)
{
	t_token	*token_;

	token_ = token;
	free(token_->str);
	free(token_);
}

int	is_redir(t_token_type type)
{
	return (type == INFILE || type == OUTFILE \
		|| type == HEREDOC || type == APPEND);
}
