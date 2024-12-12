/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:40:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/07 11:31:37 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

// check for "parent"-type builtin
int	is_p_builtin_name(char *name)
{
	if (!name)
		return (0);
	return (ft_strcmp(name, "cd") == 0 || ft_strcmp(name, "exit") == 0
		|| ft_strcmp(name, "export") == 0 || ft_strcmp(name, "unset") == 0);
}

int	is_builtin_name(char *name)
{
	if (!name)
		return (0);
	return (is_p_builtin_name(name) || ft_strcmp(name, "env") == 0
		|| ft_strcmp(name, "pwd") == 0 || ft_strcmp(name, "echo") == 0);
}
