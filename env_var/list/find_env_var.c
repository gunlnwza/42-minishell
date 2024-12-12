/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:39:58 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/10 17:47:17 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

// return ptr to the env_var's node having "key"
t_env_var	*find_env_var(char *key, t_env_var_list *env_var_list)
{
	t_env_var_list	*node;
	t_env_var		*var;

	node = find_env_var_node(key, env_var_list);
	if (node == NULL)
		return (NULL);
	var = node->content;
	return (var);
}
