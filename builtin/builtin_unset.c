/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:03 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/16 16:38:25 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static void	unset_single_var(char *key, t_shell_data *data)
{
	del_env_var(key, &data->env_var_list);
}

// - delete environment variable(s)
// - usage: unset name ...
// - iterate over each argv, and unset!
// - no condition on name, just unset name!
t_exit_status	builtin_unset(int argc, char **argv, t_shell_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		unset_single_var(argv[i], data);
		i++;
	}
	return (SUCCESS);
}
