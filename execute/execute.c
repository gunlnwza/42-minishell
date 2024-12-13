/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/12/13 15:42:23 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		ft_childprocess(t_list **cmd_lst_first, t_list *cmd_lst,
			int *prev_fd, t_shell_data *envp);
int		wait_for_all_processes(t_list *cmd_lst);
void	ft_parentprocess(t_list *cmd_lst, int *prev_fd, t_execute *cmd);

static void	issue_command_to_child(t_list **cmd_lst_first, t_list *cmd_lst,
	int *prev_fd, t_shell_data *envp)
{
	restore_terminal_settings();
	envp->exit_status = ft_childprocess(cmd_lst_first, cmd_lst, prev_fd, envp);
	free_execute_command_list(cmd_lst_first);
	builtin_exit(NULL, envp);
}

int	sub_execute(t_list **cmd_lst_first, t_shell_data *envp, int *prev_fd)
{
	t_list		*node;
	t_execute	*cmd;

	node = *cmd_lst_first;
	while (node)
	{
		cmd = node->content;
		if (cmd->command->argv)
		{
			if (node->next && pipe(cmd->pipe_fds) == -1)
				exit(EXIT_FAILURE);
			cmd->pid = fork();
			if (cmd->pid < 0)
				exit(EXIT_FAILURE);
			if (cmd->pid == 0)
				issue_command_to_child(cmd_lst_first, node, prev_fd, envp);
			else
				ft_parentprocess(node, prev_fd, cmd);
		}
		node = node->next;
	}
	return (SUCCESS);
}

t_exit_status	main_execute(t_list **commands, t_shell_data *envp)
{
	t_list	*execute_command_list;
	int		prev_fd;
	int		exit_status;

	execute_command_list = init_execute_command_list(*commands);
	ft_lstclear(commands, NULL);
	if (execute_command_list == NULL)
		return (ERROR);
	run_heredocs(execute_command_list);
	prev_fd = -1;
	if (single_builtin(execute_command_list, envp) == SUCCESS)
	{
		free_execute_command_list(&execute_command_list);
		return (envp->exit_status);
	}
	sub_execute(&execute_command_list, envp, &prev_fd);
	exit_status = wait_for_all_processes(execute_command_list);
	disable_echo_cntl();
	free_execute_command_list(&execute_command_list);
	return (exit_status);
}
