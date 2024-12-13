/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/13 15:50:35 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "../libft/libft.h"
#include "../parser/parse_line.h"
#include "../setup/setup.h"
#include "builtin.h"

#define DONT_EXIT -1

static int	is_number(char *str)
{
	int		num;
	char	*str2;
	int		compare_result;

	if (*str == '+')
		str++;
	num = ft_atoi(str);
	str2 = ft_itoa(num);
	if (str2 == NULL)
		return (FALSE);
	compare_result = ft_strcmp(str, str2);
	free(str2);
	return (compare_result == 0);
}

static int	numeric_arg_required_error(char *str)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	return (2);
}

static int	get_exit_status_from_cmd(t_exit_status *status, t_command *cmd)
{
	if (cmd->argc > 2)
	{
		if (is_number(cmd->argv[1]))
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", \
				STDERR_FILENO);
			return (ERROR);
		}
		else
			*status = numeric_arg_required_error(cmd->argv[1]);
	}
	else if (cmd->argc == 2)
	{
		if (is_number(cmd->argv[1]))
			*status = ft_atoi(cmd->argv[1]) % 256;
		else
			*status = numeric_arg_required_error(cmd->argv[1]);
	}
	return (SUCCESS);
}

// exit minishell
// command_list == NULL to exit immediately
// set data->exit_status to ERROR if too many arguments

// *** if argc == 0, argv == NULL --> free(data), and exit(data->exit_status)
t_exit_status	builtin_exit(t_command *cmd, t_shell_data *data)
{
	t_exit_status	exit_status;

	exit_status = data->exit_status;
	if (cmd)
	{
		printf("exit\n");
		if (get_exit_status_from_cmd(&exit_status, cmd) != SUCCESS)
			return (ERROR);
		free_command(cmd);
	}
	free_shell_data(data);
	restore_terminal_settings();
	exit(exit_status);
}
