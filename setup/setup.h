/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:57:55 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/09 17:21:12 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "constants.h"
# include "shell_data.h"

# define READ_MODE 0
# define EXECUTE_MODE -1

t_shell_data	*init_minishell(int argc, char **argv, char **envp);

void			disable_echo_cntl(void);
void			restore_terminal_settings(void);

void			setup_signal(void);

#endif
