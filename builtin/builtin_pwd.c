/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:45 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 16:57:55 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "builtin.h"

// print current working directory
t_exit_status	builtin_pwd(int argc, char **argv, t_shell_data *data)
{
	char	*path;

	(void) argc;
	(void) argv;
	path = get_env_value("PWD", data->env_var_list);
	if (path)
	{
		printf("%s\n", path);
		return (SUCCESS);
	}
	path = ft_getcwd();
	if (path)
	{
		printf("%s\n", path);
		free(path);
		return (SUCCESS);
	}
	path = ".";
	printf("%s\n", path);
	return (SUCCESS);
}
