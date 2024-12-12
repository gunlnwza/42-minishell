/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:18:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 16:13:27 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static char	*get_path(int argc, char **argv, t_list *env_var_list)
{
	char	*path;

	if (argc == 1)
	{
		path = get_env_value("HOME", env_var_list);
		if (path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			return (NULL);
		}
	}
	else
		path = argv[1];
	return (path);
}

static int	update_shell_variable(char *old_path, t_shell_data *data)
{
	char			*current_path;
	t_env_var_list	*set_node;

	set_node = set_env_var("OLDPWD", old_path, &data->env_var_list);
	if (set_node == NULL)
		return (ERROR);
	current_path = ft_getcwd();
	if (current_path == NULL)
		return (ERROR);
	set_node = set_env_var("PWD", current_path, &data->env_var_list);
	free(current_path);
	if (set_node == NULL)
		return (ERROR);
	return (SUCCESS);
}

static int	change_directory(char *old_path, char *new_path,
				t_shell_data *data)
{
	if (chdir(new_path) != SUCCESS)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(new_path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (ERROR);
	}
	if (update_shell_variable(old_path, data) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data)
{
	char	*old_path;
	char	*new_path;

	if (argc >= 3)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return (ERROR);
	}
	old_path = get_env_value("PWD", data->env_var_list);
	new_path = get_path(argc, argv, data->env_var_list);
	if (new_path == NULL)
		return (ERROR);
	if (change_directory(old_path, new_path, data) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
