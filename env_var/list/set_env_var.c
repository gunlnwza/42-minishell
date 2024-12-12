/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:45:25 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 13:45:42 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

static t_list	*append_new_var(char *key, char *value,
					t_env_var_list **env_var_list)
{
	t_env_var	*var;
	t_list		*node;

	var = create_env_var(key, value);
	if (var == NULL)
		return (NULL);
	node = ft_lstnew_add_back(env_var_list, var);
	if (node == NULL)
	{
		free_env_var(var);
		return (NULL);
	}
	return (node);
}

// return address of env_var's node if malloc'd successfully, NULL if not
// - if key is already in the list, replace value
//
// NOTE: "make a hard copy of value before freeing old and assigning"
//
// can have "value == NULL" if only key is declared
t_env_var_list	*set_env_var(char *key, char *value,
					t_env_var_list **env_var_list)
{
	t_list		*node;
	t_list		*new_node;
	t_env_var	*var;
	char		*temp;

	node = find_env_var_node(key, *env_var_list);
	if (node)
	{
		var = node->content;
		if (value)
		{
			temp = ft_strdup(value);
			if (temp == NULL)
				return (NULL);
			free(var->value);
			var->value = temp;
		}
		return (node);
	}
	new_node = append_new_var(key, value, env_var_list);
	if (new_node == NULL)
		return (NULL);
	return (new_node);
}
