/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_var_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:05:43 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 15:40:29 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

static void	process_special_env_var(char *key, char **value)
{
	int		num;
	char	*temp;

	if (ft_strcmp(key, "SHLVL") == 0)
	{
		num = ft_atoi(*value);
		temp = ft_itoa(num + 1);
		free(*value);
		if (temp == NULL)
		{
			*value = NULL;
			return ;
		}
		*value = temp;
	}
}

static int	process_one_line(char *env_var_line, t_list **list)
{
	char	**key_value_pair;
	t_list	*added_node;

	key_value_pair = split_env_var_line(env_var_line);
	if (key_value_pair == NULL)
		return (ERROR);
	process_special_env_var(key_value_pair[0], &key_value_pair[1]);
	if (key_value_pair[1] == NULL)
		return (ERROR);
	added_node = set_env_var(key_value_pair[0], key_value_pair[1], list);
	ft_free_str_arr(key_value_pair, 2);
	if (added_node == NULL)
		return (ERROR);
	return (SUCCESS);
}

t_list	*create_env_var_list(char **envp)
{
	t_list	*list;

	list = NULL;
	while (*envp)
	{
		if (process_one_line(*envp, &list) != SUCCESS)
		{
			free_env_var_list(&list);
			return (NULL);
		}
		envp++;
	}
	return (list);
}
