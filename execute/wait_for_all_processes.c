/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_all_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:14:34 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/12/06 16:55:42 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	wait_for_all_processes(t_list *cmd_lst)
{
	int			status;
	int			exit_status;
	t_execute	*cmd;

	status = SUCCESS;
	exit_status = SUCCESS;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		if (cmd->pid > 0)
			waitpid(cmd->pid, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_status = WTERMSIG(status) + 128;
		cmd_lst = cmd_lst->next;
	}
	return (exit_status);
}
