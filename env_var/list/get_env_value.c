/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:39:58 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/10 17:48:55 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

// search <key>, return ptr to <value>
char	*get_env_value(char *key, t_env_var_list *env_var_list)
{
	t_env_var_list	*node;
	t_env_var		*var;

	node = find_env_var_node(key, env_var_list);
	if (node == NULL)
		return (NULL);
	var = node->content;
	return (var->value);
}
