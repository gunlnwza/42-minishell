/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:32:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/10 17:12:01 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../parser/parse_line.h"
# include "../setup/setup.h"

extern int		g_signal_global;

// < connect to execute >
int				is_builtin_name(char *name);
int				is_p_builtin_name(char *name);
t_exit_status	execute_builtin(t_command *command, t_shell_data *data);
t_exit_status	p_execute_built(t_command *cmd, t_shell_data *data);

// putting
t_exit_status	builtin_echo(int argc, char **argv, t_shell_data *data);

// directories
t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_pwd(int argc, char **argv, t_shell_data *data);

// directories-utils
char			*ft_getcwd(void);

// environment variables
t_exit_status	builtin_env(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_export(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_unset(int argc, char **argv, t_shell_data *data);

// free everything and exit
t_exit_status	builtin_exit(t_command *command, t_shell_data *data);

#endif
