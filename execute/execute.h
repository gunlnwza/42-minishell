/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:16:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/12/06 16:56:14 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdio.h>
# include <fcntl.h>

# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../setup/setup.h"
# include "../parser/parse_line.h"
# include "../env_var/env_var.h"
# include "../builtin/builtin.h"

typedef struct s_execute
{
	t_command	*command;
	int			pipe_fds[2];
	int			fd_prev;
	int			fd_in;
	int			fd_out;
	int			fd_heredoc;
	pid_t		pid;
}	t_execute;

t_exit_status	main_execute(t_list **command, t_shell_data *envp);

t_list			*init_execute_command_list(t_list *commands);
void			free_execute_command_list(t_list **execute_command_list);
void			free_execute_command(void *execute_command);

char			*find_path(char *key, t_list *env_var_lst, char *cmd);
int				check_infiles(t_list *token);
char			*join_path(char **full_path, char *cmd);

void			run_heredocs(t_list *cmd_lst);

int				single_builtin(t_list *cmd_lst, t_shell_data *envp);

#endif
