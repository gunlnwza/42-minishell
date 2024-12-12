/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:01:46 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/10 17:49:25 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../setup/shell_data.h"
#include "../tokenize/token.h"

// return ERROR if malloc error, else return SUCCESS
int	expand_variable(t_list *cur_node, t_shell_data *data)
{
	t_token	*subtoken;
	char	*key;
	char	*value;
	t_list	*env_var_node;

	subtoken = cur_node->content;
	if (subtoken->type == EXIT_STATUS)
		value = ft_itoa(data->exit_status);
	else
	{
		key = subtoken->str + 1;
		env_var_node = find_env_var_node(key, data->env_var_list);
		if (env_var_node)
			value = ft_strdup(((t_env_var *) env_var_node->content)->value);
		else
			value = ft_strdup("");
	}
	if (value == NULL)
		return (ERROR);
	free(subtoken->str);
	subtoken->str = value;
	return (SUCCESS);
}
