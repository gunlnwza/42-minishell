/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:39:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/15 13:34:39 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../tokenize/token.h"
#include "command.h"

t_command	*malloc_command(void)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (command == NULL)
		return (command);
	command->argc = 0;
	command->argv = NULL;
	command->redirs = NULL;
	return (command);
}

void	free_command(void *command)
{
	t_command	*command_;
	int			i;

	command_ = command;
	i = 0;
	while (command_->argv[i])
	{
		free(command_->argv[i]);
		i++;
	}
	free(command_->argv);
	ft_lstclear(&command_->redirs, free_token);
	free(command_);
}
