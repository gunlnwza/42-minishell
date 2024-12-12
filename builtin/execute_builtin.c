/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:38:39 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/07 11:37:03 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

// for "parent"-type builtin
t_exit_status	p_execute_built(t_command *cmd, t_shell_data *data)
{
	int		argc;
	char	**argv;
	char	*name;

	argc = cmd->argc;
	argv = cmd->argv;
	name = argv[0];
	if (ft_strcmp(name, "cd") == 0)
		data->exit_status = builtin_cd(argc, argv, data);
	else if (ft_strcmp(name, "exit") == 0)
		data->exit_status = builtin_exit(cmd, data);
	else if (ft_strcmp(name, "export") == 0)
		data->exit_status = builtin_export(argc, argv, data);
	else if (ft_strcmp(name, "unset") == 0)
		data->exit_status = builtin_unset(argc, argv, data);
	else
		ft_putstr_fd("execute_builtin: builtin name not found " \
			"(cd, exit, export, unset)\n", STDERR_FILENO);
	return (data->exit_status);
}

t_exit_status	execute_builtin(t_command *command, t_shell_data *data)
{
	int			argc;
	char		**argv;
	char		*name;

	argc = command->argc;
	argv = command->argv;
	name = argv[0];
	if (is_p_builtin_name(name))
		data->exit_status = p_execute_built(command, data);
	else if (ft_strcmp(name, "echo") == 0)
		data->exit_status = builtin_echo(argc, argv, data);
	else if (ft_strcmp(name, "env") == 0)
		data->exit_status = builtin_env(argc, argv, data);
	else if (ft_strcmp(name, "pwd") == 0)
		data->exit_status = builtin_pwd(argc, argv, data);
	else
		ft_putstr_fd("execute_builtin: builtin name not found " \
			"(cd, exit, export, unset) (echo, env, pwd)\n", STDERR_FILENO);
	return (data->exit_status);
}
