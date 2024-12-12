/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:13:53 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 12:40:06 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "../../libft/list/t_list.h"

typedef t_list	t_command_list;

// command class
typedef struct s_command
{
	int		argc;
	char	**argv;
	t_list	*redirs;
}	t_command;

t_command	*malloc_command(void);
void		free_command(void *command);

#endif
