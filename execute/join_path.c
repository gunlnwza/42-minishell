/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:43:30 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/20 01:25:42 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*join_path(char **full_path, char *cmd)
{
	char	*full_path_with_cmd;

	while (*full_path)
	{
		full_path_with_cmd = ft_strjoin_all(3, *full_path, "/", cmd);
		if (access(full_path_with_cmd, X_OK) == SUCCESS)
			return (full_path_with_cmd);
		free(full_path_with_cmd);
		full_path++;
	}
	return (NULL);
}
