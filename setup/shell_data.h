/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:02:20 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:41:10 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_DATA_H
# define SHELL_DATA_H

# include "../libft/list/t_list.h"
# include "../env_var/env_var.h"

typedef int	t_exit_status;

typedef struct s_shell_data
{
	t_exit_status	exit_status;
	t_env_var_list	*env_var_list;
}	t_shell_data;

t_shell_data	*create_shell_data(int argc, char **argv, char **envp);
void			free_shell_data(t_shell_data *data);

#endif
