/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:36:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:04:48 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_data.h"

t_shell_data	*create_shell_data(int argc, char **argv, char **envp)
{
	t_shell_data	*data;

	(void) argc;
	(void) argv;
	data = malloc(sizeof(t_shell_data));
	if (data == NULL)
		return (NULL);
	data->env_var_list = create_env_var_list(envp);
	if (data->env_var_list == NULL)
	{
		free(data);
		return (NULL);
	}
	data->exit_status = EXIT_SUCCESS;
	return (data);
}

void	free_shell_data(t_shell_data *data)
{
	free_env_var_list(&data->env_var_list);
	free(data);
}
