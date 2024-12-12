/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env_var_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:39:33 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 16:11:56 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

char	*get_key_part_from_envp(char *env_var_line)
{
	char	*first_equal_sign;
	size_t	key_length;
	char	*key;

	first_equal_sign = ft_strchr(env_var_line, '=');
	key_length = first_equal_sign - env_var_line;
	key = ft_substr(env_var_line, 0, key_length);
	if (key == NULL)
		return (NULL);
	return (key);
}

char	*get_value_part_from_envp(char *env_var_line)
{
	char	*first_equal_sign;
	size_t	key_length;
	size_t	value_length;
	char	*value;

	first_equal_sign = ft_strchr(env_var_line, '=');
	key_length = first_equal_sign - env_var_line;
	value_length = ft_strlen(first_equal_sign + 1);
	value = ft_substr(env_var_line, key_length + 1, value_length);
	if (value == NULL)
		return (NULL);
	return (value);
}

// only accept <key>=<value> form
char	**split_env_var_line(char *env_var_line)
{
	char	**key_value_pair;

	key_value_pair = malloc(2 * sizeof(char *));
	if (key_value_pair == NULL)
		return (NULL);
	key_value_pair[0] = get_key_part_from_envp(env_var_line);
	key_value_pair[1] = get_value_part_from_envp(env_var_line);
	if (key_value_pair[0] == NULL || key_value_pair[1] == NULL)
	{
		free(key_value_pair[0]);
		free(key_value_pair[1]);
		free(key_value_pair);
		return (NULL);
	}
	return (key_value_pair);
}
