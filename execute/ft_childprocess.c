/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:43:59 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/07 14:33:51 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <unistd.h>

void	handle_redir_input_output(t_list *cmd_lst);

static void	do_redirs(t_list *cmd_lst, t_execute *cmd, int *prev_fd)
{
	if (cmd_lst->next)
	{
		dup2(cmd->pipe_fds[1], STDOUT_FILENO);
		close(cmd->pipe_fds[1]);
		close(cmd->pipe_fds[0]);
	}
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, STDIN_FILENO);
		close(*prev_fd);
	}
	if (cmd->command->redirs)
		handle_redir_input_output(cmd_lst);
}

static void	free_cmd_lst_if_exit(t_list **cmd_lst_first, t_command *command)
{
	t_list		*next;
	t_execute	*cmd;

	while (*cmd_lst_first)
	{
		next = (*cmd_lst_first)->next;
		cmd = (*cmd_lst_first)->content;
		if (cmd->command == command)
			ft_lstdelone(*cmd_lst_first, free);
		else
			ft_lstdelone(*cmd_lst_first, free_execute_command);
		*cmd_lst_first = next;
	}
}

static int	execute(char **cmd, t_list *env_var_list)
{
	char	*path;
	char	**envp;

	if (!cmd || !cmd[0])
		return (SUCCESS);
	if (ft_strchr(cmd[0], '/') && access(cmd[0], X_OK) == SUCCESS)
		path = ft_strdup(cmd[0]);
	else
		path = find_path("PATH", env_var_list, cmd[0]);
	if (path == NULL)
	{
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		return (ISSUE_PATH);
	}
	envp = get_envp_arr(env_var_list);
	if (envp == NULL)
		return (ERROR);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_free_str_arr(envp, 0);
		return (ISSUE_PATH);
	}
	return (SUCCESS);
}

// return exit status
int	ft_childprocess(t_list **cmd_lst_first, t_list *cmd_lst,
		int *prev_fd, t_shell_data *envp)
{
	t_execute	*cmd;
	t_command	*command;

	cmd = cmd_lst->content;
	command = cmd->command;
	if (check_infiles(command->redirs) == ERROR)
		return (ERROR);
	do_redirs(cmd_lst, cmd, prev_fd);
	if (is_builtin_name(command->argv[0]))
	{
		if (ft_strcmp(command->argv[0], "exit") == 0)
			free_cmd_lst_if_exit(cmd_lst_first, command);
		return (execute_builtin(command, envp));
	}
	return (execute(command->argv, envp->env_var_list));
}
