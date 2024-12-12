/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:13:31 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:08:26 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "../../libft/list/t_list.h"

typedef enum e_quote_state
{
	OUTSIDE = 0,
	INSIDE_SINGLE_QUOTE = 1,
	INSIDE_DOUBLE_QUOTE = 2
}	t_quote_state;

typedef enum e_subtoken_type
{
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	VARIABLE,
	EXIT_STATUS,
	NORMAL
}	t_subtoken_type;

typedef enum e_token_type
{
	WORD = 10,
	REDIR = 20,
	INFILE = 21,
	OUTFILE = 22,
	HEREDOC = 23,
	APPEND = 24,
	PIPE = 30
}	t_token_type;

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

typedef t_list	t_token_list;

t_list	*tokenize_line(char *line);

t_token	*create_token(char *str, int type);
void	*copy_token(void *token);
void	free_token(void *content);

int		is_redir(t_token_type type);

#endif
