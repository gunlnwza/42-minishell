/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:45:17 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 13:53:33 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

// from env_var_list, transform to (malloc'd) envp array
char	**get_envp_arr(t_env_var_list *env_var_list)
{
	char		**arr;
	t_env_var	*env_var;
	size_t		i;

	arr = malloc((ft_lstsize(env_var_list) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (env_var_list)
	{
		env_var = env_var_list->content;
		if (env_var->value)
			arr[i] = ft_strjoin_all(3, env_var->key, "=", env_var->value);
		else
			arr[i] = ft_strjoin_all(3, env_var->key, "=", "");
		if (arr[i] == NULL)
		{
			ft_free_str_arr(arr, i);
			return (NULL);
		}
		i++;
		env_var_list = env_var_list->next;
	}
	arr[i] = NULL;
	return (arr);
}
