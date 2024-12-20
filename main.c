/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/20 16:14:39 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft/libft.h"
#include "setup/setup.h"
#include "parser/parse_line.h"
#include "builtin/builtin.h"
#include "execute/execute.h"

int		g_signal;
char	*read_line(t_shell_data *data);

static void	evaluate_line(char *line, t_shell_data *data)
{
	t_command_list	*commands;
	int				ret;

	if (ft_strlen(line) == 0)
	{
		data->exit_status = SUCCESS;
		return ;
	}
	commands = NULL;
	ret = parse_line(line, data, &commands);
	if (ret == EINVAL || commands == NULL)
	{
		data->exit_status = ENOENT;
		return ;
	}
	else if (ret == ENOMEM)
		builtin_exit(NULL, data);
	data->exit_status = main_execute(&commands, data);
}

static void	main_loop(t_shell_data *data)
{
	char	*line;

	while (TRUE)
	{
		g_signal = READ_MODE;
		line = read_line(data);
		if (g_signal != READ_MODE)
			data->exit_status = g_signal;
		if (line == NULL)
		{
			if (errno == ENOMEM)
				data->exit_status = ENOMEM;
			else
				printf("exit\n");
			builtin_exit(NULL, data);
		}
		g_signal = EXECUTE_MODE;
		evaluate_line(line, data);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell_data	*data;
	int				i;

	data = init_minishell(argc, argv, envp);
	if (data == NULL)
		return (EXIT_FAILURE);
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			evaluate_line(argv[i], data);
			i++;
		}
	}
	main_loop(data);
}
