/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:39:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/06 17:30:16 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include "../setup/shell_data.h"

# include "tokenize/token.h"
# include "create_commands/command.h"

int	parse_line(char *line, t_shell_data *data,
		t_command_list **commands);

#endif
