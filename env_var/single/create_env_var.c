/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:46:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 13:38:49 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

static int	assign_value(t_env_var *var, char *value)
{
	if (value == NULL)
	{
		var->value = NULL;
		return (SUCCESS);
	}
	var->value = ft_strdup(value);
	if (var->value == NULL)
		return (ERROR);
	return (SUCCESS);
}

// can have "value == NULL" if only key is declared
t_env_var	*create_env_var(char *key, char *value)
{
	t_env_var	*var;

	var = malloc(sizeof(t_env_var));
	if (var == NULL)
		return (NULL);
	var->key = ft_strdup(key);
	if (var->key == NULL)
	{
		free(var);
		return (NULL);
	}
	if (assign_value(var, value) != SUCCESS)
	{
		free(var->key);
		free(var);
		return (NULL);
	}
	return (var);
}
