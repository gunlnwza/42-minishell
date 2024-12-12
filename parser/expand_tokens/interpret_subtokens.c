/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_subtokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:05:19 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../libft/libft.h"
#include "../../setup/shell_data.h"
#include "../tokenize/token.h"

int	interpret_single_subtoken(t_list **subtokens, t_list *cur_node,
		t_shell_data *data, int *state);

// return ERROR if malloc error
// return SUCCESS otherwise; (be careful, subtokens could be empty afterward)
int	interpret_subtokens(t_list **subtokens, t_shell_data *data)
{
	t_list	*cur_node;
	t_list	*next_node;
	int		state;

	cur_node = *subtokens;
	state = OUTSIDE;
	while (cur_node)
	{
		next_node = cur_node->next;
		if (interpret_single_subtoken(subtokens, cur_node, data, &state)
			!= SUCCESS)
			return (ERROR);
		cur_node = next_node;
	}
	return (SUCCESS);
}
