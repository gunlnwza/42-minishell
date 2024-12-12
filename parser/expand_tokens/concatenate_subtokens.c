/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_subtokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/15 16:12:31 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../tokenize/token.h"

static char	*malloc_word(t_list *subtokens)
{
	t_token	*subtoken;
	size_t	length;

	length = 0;
	while (subtokens)
	{
		subtoken = subtokens->content;
		length += ft_strlen(subtoken->str);
		subtokens = subtokens->next;
	}
	return (malloc(sizeof(char) * (length + 1)));
}

char	*concatenate_subtokens(t_list *subtokens)
{
	char	*word;
	size_t	word_length;
	size_t	subtoken_length;
	t_token	*subtoken;

	word = malloc_word(subtokens);
	if (word == NULL)
		return (NULL);
	word_length = 0;
	while (subtokens)
	{
		subtoken = subtokens->content;
		subtoken_length = ft_strlen(subtoken->str);
		ft_memcpy(word + word_length, subtoken->str, subtoken_length);
		word_length += subtoken_length;
		subtokens = subtokens->next;
	}
	word[word_length] = '\0';
	return (word);
}
