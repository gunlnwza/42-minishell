/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/09 17:23:27 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "../libft/libft.h"
#include "../parser/parse_line.h"
#include "../setup/setup.h"
#include "builtin.h"

// exit minishell
// command_list == NULL to exit immediately
// set data->exit_status to ERROR if too many arguments

// *** if argc == 0, argv == NULL --> free(data), and exit(data->exit_status)
t_exit_status	builtin_exit(t_command *command, t_shell_data *data)
{
	t_exit_status	exit_status;

	if (command && command->argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", \
			STDERR_FILENO);
		return (ERROR);
	}
	exit_status = data->exit_status;
	if (command)
	{
		if (command->argc == 2)
			exit_status = ft_atoi(command->argv[1]);
		free_command(command);
	}
	free_shell_data(data);
	restore_terminal_settings();
	exit(exit_status);
}
