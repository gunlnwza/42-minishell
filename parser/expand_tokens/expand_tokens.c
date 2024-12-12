/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:59:43 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:03:58 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../libft/libft.h"
#include "../../setup/shell_data.h"
#include "../tokenize/token.h"

t_list	*chop_word(char *word);
int		interpret_subtokens(t_list **subtokens, t_shell_data *data);
char	*concatenate_subtokens(t_list *subtokens);

// - free word and replace token->word with expanded word
// - if malloc error, set *word = NULL
static void	expand_word(char **token_str, t_shell_data *data)
{
	t_list	*subtokens;
	char	*new_word;
	int		ret;

	subtokens = chop_word(*token_str);
	free(*token_str);
	*token_str = NULL;
	if (subtokens == NULL)
		return ;
	ret = interpret_subtokens(&subtokens, data);
	if (ret == ENOMEM)
	{
		ft_lstclear(&subtokens, free_token);
		return ;
	}
	new_word = concatenate_subtokens(subtokens);
	ft_lstclear(&subtokens, free_token);
	if (new_word == NULL)
		return ;
	*token_str = new_word;
}

// input: raw tokens
// output: dequoted, expanded $, and expanded path
// - if malloc error, tokens will be freed and set to NULL
void	expand_tokens(t_list **tokens, t_shell_data *data)
{
	t_list	*node;
	t_token	*token;

	node = *tokens;
	while (node)
	{
		token = node->content;
		if (token->type == WORD)
		{
			expand_word(&token->str, data);
			if (token->str == NULL)
			{
				ft_lstclear(tokens, free_token);
				return ;
			}
		}
		node = node->next;
	}
}
