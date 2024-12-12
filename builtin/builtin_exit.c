/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/12 18:53:22 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "../libft/libft.h"
#include "../parser/parse_line.h"
#include "../setup/setup.h"
#include "builtin.h"


static int	is_arg_correct(char *str)
{
	int		num;
	char	*str2;
	int		compare_result;

	num = ft_atoi(str);
	str2 = ft_itoa(num);
	if (str2 == NULL)
		return (FALSE);
	compare_result = ft_strcmp(str, str2);
	free(str2);
	if (compare_result != 0)
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		return (FALSE);
	}
	return (TRUE);
}

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
		{
			if (is_arg_correct(command->argv[1]))
				exit_status = ft_atoi(command->argv[1]) % 256;
			else
				exit_status = 2;
		}
		free_command(command);
	}
	free_shell_data(data);
	restore_terminal_settings();
	exit(exit_status);
}
