/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:45:24 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/10 17:45:30 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

// return ptr to the env_var's node having "key"
t_env_var_list	*find_env_var_node(char *key, t_env_var_list *env_var_list)
{
	t_env_var	*var;

	while (env_var_list)
	{
		var = env_var_list->content;
		if (ft_strcmp(var->key, key) == 0)
			return (env_var_list);
		env_var_list = env_var_list->next;
	}
	return (NULL);
}
