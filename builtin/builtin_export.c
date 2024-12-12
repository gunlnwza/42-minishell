/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 16:11:40 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "builtin.h"
#include "../libft/libft.h"
#include "../env_var/env_var.h"

static void	sort_envp_arr(char **arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (arr[i + 1])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	print_declared_variables(t_env_var_list *list)
{
	char	**arr;
	int		i;
	char	**key_value;

	arr = get_envp_arr(list);
	if (arr == NULL)
		return (ERROR);
	sort_envp_arr(arr);
	i = 0;
	while (arr[i])
	{
		key_value = split_env_var_line(arr[i]);
		if (ft_strlen(key_value[1]) == 0)
			arr[i][ft_strlen(arr[i]) - 1] = '\0';
		printf("declare -x %s\n", arr[i]);
		ft_free_str_arr(key_value, 2);
		i++;
	}
	ft_free_str_arr(arr, 0);
	return (SUCCESS);
}

static int	export_single_var(char *key_value_str, t_shell_data *data)
{
	char	**key_value_pair;
	char	*key_str;
	t_list	*node;

	if (ft_strchr(key_value_str, '='))
	{
		key_value_pair = split_env_var_line(key_value_str);
		if (key_value_pair == NULL)
			return (ENOMEM);
		if (!is_valid_key(key_value_pair[0]))
			return (ERROR);
		node = set_env_var(key_value_pair[0], key_value_pair[1],
				&data->env_var_list);
		ft_free_str_arr(key_value_pair, 2);
		if (node == NULL)
			return (ENOMEM);
	}
	else
	{
		key_str = key_value_str;
		if (!is_valid_key(key_str))
			return (ERROR);
		set_env_var(key_str, NULL, &data->env_var_list);
	}
	return (SUCCESS);
}

// - set environment variable(s)
//
// - usage: export key[=value] ...
//
// - iterate over each argv
// - valid key: [A-Za-z][A-Za-z0-9_]+
// - if value is not given, don't set env var
t_exit_status	builtin_export(int argc, char **argv, t_shell_data *data)
{
	t_exit_status	ret;
	int				export_status;
	int				i;

	if (argc == 1)
		return (print_declared_variables(data->env_var_list));
	ret = SUCCESS;
	i = 1;
	while (i < argc)
	{
		export_status = export_single_var(argv[i], data);
		if (export_status == ENOMEM)
			return (ENOMEM);
		else if (export_status == ERROR)
		{
			ret = ERROR;
			ft_putstr_fd("minishell: export: '", STDERR_FILENO);
			ft_putstr_fd(argv[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		i++;
	}
	return (ret);
}
